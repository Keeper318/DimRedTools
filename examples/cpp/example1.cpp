#include <iostream>
#include "DimRedTools/DimRedTools.hpp"

int main(int argc, char const *argv[])
{
    std::string my_name = "Jeremy";
    std::cout << "My Name is " << my_name << std::endl;
    
    // Respond
    std::cout << dim_red_tools::Hello(my_name) << std::endl;
}
