#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace testing;

class MyClass
{
public:
    virtual void doSomething(){}
};

class MockClass : public MyClass
{
public:
    MOCK_METHOD0(doSomething, void());  // MOCK_METHOD is from gmock.h
};

TEST(MyTest, UseMockClassFromGMock)    // TEST is from gtest.h
{
    MockClass myMockClass;

    EXPECT_CALL(myMockClass, doSomething()).Times(1);
    
    myMockClass.doSomething();
}

// we write our own main because we did link to GMock::gmock and not GMock::main
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

