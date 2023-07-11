#include <iostream>
#include "handler.h"
int main()
{
    try
    {
    std::cout<<"Enter the directory you want to explore"<<std::endl;
    std::string the_path;
    std::cin>>the_path;
    Handler the_handler;
    while (!the_handler.Check_Path(the_path))
    {
    std::cout<<"Entered directory \""<<the_path<<"\" does not exist! Please, enter the correct directory"
    <<std::endl;
    std::cin>>the_path;
    }
    std::string the_format;
    std::cout<<"In a what format do you want to save the report, XML or JSON?"<<std::endl;
    std::cin>>the_format;
    while (the_format!="XML"&&the_format!="JSON")
    {
    std::cout<<"Entered incorrect format \""<<the_format<<"\"! Please, enter the correct format"<<std::endl;
    std::cin>>the_format;
    }
    if (the_format=="XML") the_handler.SetFormatType(Format::XML);
    else the_handler.SetFormatType(Format::JSON);
    the_handler.Process();
    std::cout<<"The report has been created in the entered directory. Thanks for using our platform!";
    }
    catch(const std::exception &the_error)
    {
    std::cerr<<the_error.what();
    }
    return 0;
}