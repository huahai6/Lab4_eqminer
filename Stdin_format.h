#pragma once
class Stdin_format {
    int type;//标准输入格式类型
    int left;//（）中左值大小
    int right;//（）中右值大小
public:
    //构造
    Stdin_format();
    Stdin_format(int _type, int _left, int _right);
    //get
    int get_type();
    int get_left();
    int get_right();
    //set
    void set_type(int _type);
    void set_left(int _left);
    void set_right(int _right);
};
