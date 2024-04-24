#ifndef FULLMATCH_H
#define FULLMATCH_H

#include <string>

class FullMatch {
private:
    std::string matchStr;
    
public:
    FullMatch(const std::string& str) : matchStr(str) {}
    
    bool operator()(const std::string& testName) const {
        return testName == matchStr;
    }
};

#endif