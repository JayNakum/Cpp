#include <iostream>
#include <string>

void test()
{
    std::string age = std::string("1") + "9";
    age += " years";
    // bool contains = age.find("yea") != std::string::npos;

    const char *name = "Cherno";
    "My Literal";

    using namespace std::string_literals;
    std::string age = "1"s + "9";

    const char *name = u8"Cherno"; // 1 byte per character

    const wchar_t *wide = L"Putin";    // 2 bytes per character
    const char16_t *bit16 = u"Cherno"; // 2 bytes per character

    const char32_t *bit32 = U"Cherno"; // 4 bytes per character

    const char *example = R"(Line1
    Line2
    Line3
    Line4)";

    const char* ex = "line1"
    "line2"
    "line3"
    "line4\n";

    std::cin.get();
}