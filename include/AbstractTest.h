#ifndef ABSTRACTTEST_H
#define ABSTRACTTEST_H

class AbstractTest {
public:
    virtual void SetUp() = 0;
    virtual void TearDown() = 0;
    virtual void Run() = 0;
};

#endif