#include <Geode/Geode.hpp>
#include <Geode/modify/CCLabelBMFont.hpp>

using namespace geode::prelude;

// Simple cat accent function
std::string catify(const std::string& input) {
    std::string output = input;

    for (char& c : output) {
        switch (c) {
            case 'r':
            case 'l':
                c = 'w';
                break;
            case 'R':
            case 'L':
                c = 'W';
                break;
        }
    }

    return output;
}

// Hook label text setting
class $modify(CatLabel, CCLabelBMFont) {
    void setString(const char* text, bool needUpdateLabel = true) {
        if (!text) {
            CCLabelBMFont::setString(text, needUpdateLabel);
            return;
        }

        std::string original = text;
        bool hasLetters = false;

        for (char c : original) {
            if (isalpha((unsigned char)c)) {
                hasLetters = true;
                break;
            }
        }

        std::string modified = hasLetters ? catify(original) : original;

        CCLabelBMFont::setString(modified.c_str(), needUpdateLabel);
    }
};