#include "Judge.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;
Judge::Judge() :
    input_a(NULL),
    input_b(NULL),
    output(NULL) {}
Judge::Judge(Input* _input_a, Input* _input_b, Output* _output, vector<Stdin_format*>& _sf) :
    input_a(_input_a),
    input_b(_input_b),
    output(_output),
    sf(_sf) {}
//构造随机输入
string Judge::make_random_input(int index) {
    int type = sf[index]->get_type();//得到标准输入格式类型
    int left = sf[index]->get_left();
    int right = sf[index]->get_right();
    string random_input = "";
    //类型为int
    if (type == 1) { 
        int value = left + rand() % (right - left + 1);
        random_input += to_string(value);
    }
    //类型为char
    else if (type == 2) { 
        random_input += ('a' + rand() % 26);
    }
    //类型为string
    else if (type == 3) { 
        int length = left + rand() % (right - left + 1);
        for (int i = 0; i < length; i++) {
            random_input += ('a' + rand() % 26);
        }
    }
    return random_input;
}
//产生多组随机输入用于两个OJ程序的多次执行，比较产生的多个输出结果
void Judge::execute_compare() {
    //system(g++ -w -o a.out xxxa.cpp)
    string command_a = "g++ -w -o a.out ";
    command_a += input_a->get_absolute_path();
    system(command_a.c_str());
    //system(g++ -w -o b.out xxxb.cpp)
    string command_b = "g++ -w -o b.out ";
    command_b += input_b->get_absolute_path();
    system(command_b.c_str());
    //input.txt保存构造的随机输入
    string input = input_a->get_folder_absolute_path() + "/input.txt";
    //output.txt保存当前OJ程序的输出
    string output_1 = input_a->get_folder_absolute_path() + "/output1.txt";
    string output_2 = input_b->get_folder_absolute_path() + "/output2.txt";
    //构造随机输入 10次
    for (int i = 0; i < 10; i++) {  
        ofstream out_file;
        out_file.open(input, ios::out);
        for (int j = 0; j < sf.size(); j++) {
            out_file << make_random_input(j) << ' ';
        }
        out_file << endl;
        out_file.close();
        //system(./a.out <input.txt >ouput.txt)
        string order_a = "./a.out <";
        order_a += input;
        order_a += " >";
        order_a += output_1;
        system(order_a.c_str());
        //system(./b.out <input.txt >ouput.txt)
        string order_b = "./b.out <";
        order_b += input;
        order_b+= " >";
        order_b += output_2;
        system(order_b.c_str());
 
        fstream in_file1;
        vector<string> res1;
        in_file1.open(output_1, ios::in);
        if (!in_file1) {
            exit(-1);
        }
        string res;
        while (in_file1 >> res) {
            res1.push_back(res);
        }
        in_file1.close();

        fstream in_file2;
        vector<string> res2;
        in_file2.open(output_2, ios::in);
        if (!in_file2) {
            exit(-1);
        }
        //string res;
        while (in_file2 >> res) {
            res2.push_back(res);
        }      
        in_file2.close();
        //比较输出结果
        if (res1 != res2) {
            output->set_result(false);        
            return;
        }
    }
    output->set_result(true);
}