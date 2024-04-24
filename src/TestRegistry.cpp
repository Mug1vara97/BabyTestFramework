#include "TestRegistry.h"
#include <stdexcept>
#include <algorithm>

TestRegistry& TestRegistry::Instance() {
    static TestRegistry instance;
    return instance;
}

void TestRegistry::RegisterTestClass(const std::string& testName, AbstractTest* (*createTestFunction)()) {
    testRegistry[testName] = createTestFunction;
}

AbstractTest* TestRegistry::CreateTest(const std::string& testName) {
    auto it = testRegistry.find(testName);
    if (it == testRegistry.end()) {
        throw std::out_of_range("Test not found");
    }
    
    return it->second();
}

void TestRegistry::RunTest(const std::string& testName) {
    AbstractTest* test = CreateTest(testName);
    test->SetUp();
    try {
        test->Run();
    } catch (...) {

    }
    test->TearDown();
}

void TestRegistry::RunTests(std::function<bool(const std::string&)> predicate) {
    std::vector<std::string> testsToRun;
    for (const auto& test : testRegistry) {
        if (predicate(test.first)) {
            testsToRun.push_back(test.first);
        }
    }
    
    std::sort(testsToRun.begin(), testsToRun.end());
    for (const auto& testName : testsToRun) {
        RunTest(testName);
    }
}

std::vector<std::string> TestRegistry::ShowAllTests() {
    std::vector<std::string> testNames;
    for (const auto& test : testRegistry) {
        testNames.push_back(test.first);
    }
    return testNames;
}

std::vector<std::string> TestRegistry::ShowTests(std::function<bool(const std::string&)> predicate) {
    std::vector<std::string> matchingTests;
    for (const auto& test : testRegistry) {
        if (predicate(test.first)) {
            matchingTests.push_back(test.first);
        }
    }
    return matchingTests;
}

void TestRegistry::Clear() {
    testRegistry.clear();
}
