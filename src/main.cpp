#include <iostream>
#include "TestRegistry.h"
#include "FullMatch.h"
#include "Substr.h"

class SimpleTest : public AbstractTest {
public:
    SimpleTest() {
        std::cout << "SimpleTest constructor" << std::endl;
    }
    
    void SetUp() override {
        std::cout << "SimpleTest SetUp" << std::endl;
    }
    
    void TearDown() override {
        std::cout << "SimpleTest TearDown" << std::endl;
    }
    
    void Run() override {
        std::cout << "SimpleTest Run" << std::endl;
    }
};

int main() {
    TestRegistry& registry = TestRegistry::Instance();
    
    registry.RegisterTestClass("SimpleTest", []()->AbstractTest*{return new SimpleTest;});
    
    registry.RunTest("SimpleTest");
    
    std::vector<std::string> allTests = registry.ShowAllTests();
    for (const auto& testName : allTests) {
        std::cout << "Test: " << testName << std::endl;
    }
    
    FullMatch fullMatch("SimpleTest");
    registry.RunTests(fullMatch);
    
    Substr substrMatch("Test");
    std::vector<std::string> matchingTests = registry.ShowTests(substrMatch);
    
    for (const auto& testName : matchingTests) {
        std::cout << "Matching Test: " << testName << std::endl;
    }
    
    registry.Clear();
    
    return 0;
}