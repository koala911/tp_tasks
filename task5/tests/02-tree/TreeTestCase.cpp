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
    boost::filesystem::path subdir("./my_dir_for_test/my_subdir");
    boost::filesystem::create_directories(subdir);
    std::ofstream ofs("./my_dir_for_test/my_file_for_test.txt");
    ofs.close();
    FileNode dir_node, subdir_node, file_node;
    subdir_node.name = "my_subdir";
    subdir_node.is_dir = true;
    subdir_node.children.clear();
    file_node.name = "my_file_for_test.txt";
    file_node.is_dir = false;
    file_node.children.clear();
    dir_node.name = "my_dir_for_test";
    dir_node.is_dir = true;
    dir_node.children = {subdir_node};
    ASSERT_EQ(GetTree("my_dir_for_test", true), dir_node);
    std::remove("./my_dir_for_test/my_file_for_test.txt");
}

TEST_F(TreeTestCase, TestFive) {
    boost::filesystem::path dir("./my_dir_for_test");
    boost::filesystem::create_directories(dir);
    boost::filesystem::path subdir("./my_dir_for_test/my_subdir");
    boost::filesystem::create_directories(subdir);
    std::ofstream ofs("./my_dir_for_test/my_subdir/my_file_for_test.txt");
    ofs.close();
    FileNode dir_node, subdir_node, file_node;
    file_node.name = "my_file_for_test.txt";
    file_node.is_dir = false;
    file_node.children.clear();
    subdir_node.name = "my_subdir";
    subdir_node.is_dir = true;
    subdir_node.children = {file_node};
    dir_node.name = "my_dir_for_test";
    dir_node.is_dir = true;
    dir_node.children = {subdir_node};
    ASSERT_EQ(GetTree("my_dir_for_test", false), dir_node);
    std::remove("./my_dir_for_test/my_file_for_test.txt");
}
