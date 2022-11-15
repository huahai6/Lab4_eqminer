#pragma once
#include <stdlib.h>
#include <string>
using namespace std;
class Input {
    string name;//文件名
    string absolute_path;//绝对路径
    string relative_path;//相对路径
    string folder_absolute_path;//文件所在文件夹的绝对路径
public:
    //构造
    Input();
    Input(string _name, string _absolute_path, string _relative_path, string _folder_absolute_path);
    //get
    string get_name();
    string get_absolute_path();
    string get_relative_path();
    string get_folder_absolute_path();
    //set
    void set_name(string _name);
    void set_absolute_path(string _absolute_path);
    void set_relative_path(string _relative_path);
    void set_folder_absolute_path(string _folder_absolute_path);
};