#pragma once
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/property_tree/json_parser.hpp>
class ReportGenerator
{
public:
virtual void Generate(const boost::property_tree::ptree &entered_tree,
                      std::string &entered_path) const=0;
virtual ~ReportGenerator()=default;
};
class XMLReportGenerator:public ReportGenerator
{
public:
void Generate(const boost::property_tree::ptree &entered_tree,
              std::string &entered_path) const override;
};
class JSONReportGenerator:public ReportGenerator
{
public:
void Generate(const boost::property_tree::ptree &entered_tree,
              std::string &entered_path) const override;
};