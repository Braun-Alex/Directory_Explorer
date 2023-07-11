#pragma once
#include "report_generators.h"
#include <filesystem>
enum class Format {XML,JSON};
class Handler
{
public:
bool Check_Path(const std::string &entered_path);
void SetFormatType(Format entered_type);
void Process();
private:
std::unique_ptr<ReportGenerator> the_generator {};
std::string the_path;
boost::property_tree::ptree the_report;
void GetObjectSize(const std::filesystem::directory_iterator &the_iterator,
                  uintmax_t &the_size);
};