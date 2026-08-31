#include <filetypes/bffnt.hpp>
#include <iostream>
#include <fstream>

int main()
{
    FileTypes::BFFNTFile font;

    std::ifstream file(
        "myfont.bffnt",
        std::ios::binary
    );

    if(!file.is_open())
    {
        std::cout << "Could not open font\n";
        return 1;
    }

    auto result = font.loadFromBinary(file);

    if(result != BFFNTError::NONE)
    {
        std::cout << "Load failed: "
                  << FileTypes::BFFNTErrorGetName(result)
                  << "\n";
        return 1;
    }

    char16_t testChar = 0xE000;

    size_t glyph = font.getGlyphIndex(testChar);

    std::cout
        << "Glyph index: "
        << glyph
        << "\n";

    uint8_t width = font.getWidth(testChar);

    std::cout
        << "Glyph width: "
        << (int)width
        << "\n";

    return 0;
}