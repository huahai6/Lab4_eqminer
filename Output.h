#pragma once
#include "Input.h"
class Output {
    Input* input_a;//输入对象a
    Input* input_b;//输入对象b
    bool result;//等价结果
    bool manual;//人工确认
public:
    //构造
    Output();
    Output(Input* _input_a, Input* _input_b);
    //get
    Input* get_input_a();
    Input* get_input_b();
    bool get_result();
    bool get_manual();
    //set
    void set_result(bool _result);
    void set_manual(bool _manual);
};