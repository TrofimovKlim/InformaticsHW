#include <iostream>
#include <regex>
#include <string>
#include <algorithm>

int main()
{
    std::string date = R"(cormoroi 2001.02.22 rfii3o3ke 22:56:02 klmcr;w 24:02:77 we,w 2021.03.11 efcdv 200.02.22)";
    std::regex pattern_date(R"(([0-2][0-9]{3})\.(0[1-9]|1[0-2])\.(0[1-9]|[1-2][0-9]|3[0-1]))");
    std::regex pattern_time(R"(([0-1][0-9]|2[0-3])(:[0-5][0-9]){2})");
    
    std::sregex_iterator begin(date.cbegin(), date.cend(), pattern_date);
    std::sregex_iterator end;
    std::cout << "right format date" << std::endl;
    std::for_each(begin, end, [](const std::smatch & m) {
        std::cout << m[0] << std::endl;
    });
    std::sregex_iterator begin0(date.cbegin(), date.cend(), pattern_time);
    std::cout << "right format time" << std::endl;
    std::for_each(begin0, end, [](const std::smatch & m) {
        std::cout << m[0] << std::endl;
    });
    return 0;
}
