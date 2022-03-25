//
// Created by Administrator on 3/25/2022.
//

#include "gtest/gtest.h"

extern "C" {
#include "bcr_mock.h"
}

class BCR_Cypd3177_Mock_Test:public testing::Test
{
protected:
    virtual void SetUp()
    {
        std::cout<<"SetUp"<<std::endl;
    }
    virtual void TearDown()
    {
        std::cout<<"TearDown"<<std::endl;
    }
};

TEST_F(BCR_Cypd3177_Mock_Test, Test1) {
    EXPECT_EQ(platform_write(NULL, 0, NULL, 0), 1);
}