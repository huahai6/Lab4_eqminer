#pragma once
#include "Input.h"
#include "Output.h"
#include "Stdin_format.h"
#include <vector>
class Judge {
private:
    Input* input_a;
    Input* input_b;
    Output* output;
    vector<Stdin_format*> sf;
public:
    //构造
    Judge();
    Judge(Input* _input_a, Input* _input_b, Output* _output, vector<Stdin_format*>& _sf);
    //函数
    string make_random_input(int index);
    void execute_compare();
};