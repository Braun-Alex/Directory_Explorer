#include "handler.h"
bool Handler::Check_Path(const std::string &entered_path)
{
bool the_result=std::filesystem::exists(entered_path)&&
std::filesystem::is_directory(entered_path);
if (!the_result) return false;
the_path=entered_path;
return true;
}
void Handler::SetFormatType(Format entered_type)
{
if (entered_type==Format::XML) the_generator=std::make_unique<XMLReportGenerator>();
else the_generator=std::make_unique<JSONReportGenerator>();
}
void Handler::Process()
{
std::filesystem::directory_iterator the_begin(the_path);
std::filesystem::directory_iterator the_end;
boost::property_tree::ptree the_main_tree;
for (; the_begin!=the_end; ++the_begin)
{
boost::property_tree::ptree the_object_report;
the_object_report.add("name",the_begin->path().filename().string());
std::string the_value;
if (the_begin->is_directory()) the_value="directory";
else if (the_begin->is_regular_file()) the_value="file";
else if (the_begin->is_symlink()) the_value="symbolical link";
else the_value="something other";
the_object_report.add("type",the_value);
uintmax_t the_object_size=0;
GetObjectSize(the_begin,the_object_size);
the_object_report.add("size",std::to_string(the_object_size)+" bytes");
the_main_tree.add_child("object",the_object_report);
}
the_path+="/report";
the_report.add_child("objects",the_main_tree);
the_generator->Generate(the_report,the_path);
}
void Handler::GetObjectSize(const std::filesystem::directory_iterator &the_iterator,
                  uintmax_t &the_size)
{
if (the_iterator->is_regular_file())
{
the_size+=the_iterator->file_size();
return;
}
if (the_iterator->is_directory())
{
std::filesystem::directory_iterator another_begin(the_iterator->path());
std::filesystem::directory_iterator another_end;
for (; another_begin!=another_end; ++another_begin) GetObjectSize(another_begin,the_size);
}
}