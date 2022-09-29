#include <iostream>
#include <regex>
#include <string>
#include <algorithm>

int main() {
    std::string data =  ". one more "
    "kl,oknjuhbgvf " //correct
    "hello@world.edu some text " //correct
    " JJ ";
    std::regex pattern (R"(\s[^.]([[:alnum:]!#$%&'*+-/=?^_`{|}~]+[.]?)*[^.]@([^-][[:alnum:]-]+.[[:alnum:]-]+[^-]))");
    std::sregex_iterator begin(data.cbegin(), data.cend(), pattern);
    std::sregex_iterator end;
    std::for_each(begin, end, [](const std::smatch& m) {
        std::cout << m.str(2) << std::endl;
    });
    system("pause");
    return 0;
}
