#include "report_generators.h"
void XMLReportGenerator::Generate(const boost::property_tree::ptree &entered_tree,
                                  std::string &entered_path) const
{
entered_path+=".xml";
boost::property_tree::write_xml(entered_path,entered_tree);
}
void JSONReportGenerator::Generate(const boost::property_tree::ptree &entered_tree,
                                   std::string &entered_path) const
{
entered_path+=".json";
boost::property_tree::write_json(entered_path,entered_tree);
}