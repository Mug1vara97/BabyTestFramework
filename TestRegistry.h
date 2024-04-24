#ifndef TESTREGISTRY_H
#define TESTREGISTRY_H

#include <map>
#include <string>
#include <vector>
#include "AbstractTest.h"
#include <functional>

class TestRegistry {
private:
    std::map<std::string, AbstractTest*(*)()> testRegistry;
    
    TestRegistry() {}
    
public:
    static TestRegistry& Instance();
    
    void RegisterTestClass(const std::string& testName, AbstractTest* (*createTestFunction)());
    AbstractTest* CreateTest(const std::string& testName);
    
    void RunTest(const std::string& testName);
    void RunTests(std::function<bool(const std::string&)> predicate);
    
    std::vector<std::string> ShowAllTests();
    std::vector<std::string> ShowTests(std::function<bool(const std::string&)> predicate);
    
    void Clear();
};

#endif