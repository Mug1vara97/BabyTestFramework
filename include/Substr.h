#ifndef SUBSTR_H
#define SUBSTR_H

#include <string>

class Substr {
private:
    std::string substr;
    
public:
    Substr(const std::string& str) : substr(str) {}
    
    bool operator()(const std::string& testName) const {
        return testName.find(substr) != std::string::npos;
    }
};

#endif