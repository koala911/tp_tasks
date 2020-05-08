//
// Created by akhtyamovpavel on 5/1/20.
//


#include "TreeTestCase.h"
#include "Tree.h"
#include <fstream>
#include <boost/filesystem.hpp>


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
    boost::filesystem::path dir("./my_dir_for_test");
    boost::filesystem::create_directories(dir); 
    FileNode answer;
    answer.name = "my_dir_for_test";
    answer.is_dir = true;
    answer.children.clear();
    ASSERT_EQ(GetTree("my_dir_for_test", true), answer);
}

TEST_F(TreeTestCase, TestFive) {
    boost::filesystem::path dir("./my_dir_for_test");
    boost::filesystem::create_directories(dir); 
    FileNode answer;
    answer.name = "my_dir_for_test";
    answer.is_dir = true;
    answer.children.clear();
    ASSERT_EQ(GetTree("my_dir_for_test", false), answer);
}