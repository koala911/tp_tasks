//
// Created by akhtyamovpavel on 5/1/20.
//


#include "TreeTestCase.h"
#include "Tree.h"
#include <fstream>

TEST_F(TreeTestCase, TestOne) {
    ASSERT_THROW(GetTree("/wrong/path/", false), std::invalid_argument);
}

TEST_F(TreeTestCase, TestTwo) {
    std::ofstream ofs("my_file_for_test.txt"); 
    ofs.close();
    ASSERT_THROW(GetTree("my_file_for_test.txt", false), std::invalid_argument);
    std::remove("my_file_for_test.txt"); 
}

TEST_F(TreeTestCase, TestThree) {
    FileNode f1;
    ASSERT_EQ(f1 == f1, true);
}

TEST_F(TreeTestCase, TestFour) {
    ASSERT_EQ(GetTree(".", true), GetTree(".", true));
}

TEST_F(TreeTestCase, TestFive) {
    ASSERT_EQ(GetTree(".", false), GetTree(".", false));
}