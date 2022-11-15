#include "Equminer.h"

void get_input(string folder_name, string folder_absolute_path) {
    string cpp_name;//cpp文件名
    string cpp_absolute_path;//cpp文件绝对路径
    string cpp_relative_path;//cpp文件相对路径
    DIR* dir = opendir(folder_absolute_path.c_str());
    if (dir == NULL) {
        exit(-1);
    }
    dirent* cpp_dir;
    while ((cpp_dir = readdir(dir)) != NULL) {
        cpp_name = cpp_dir->d_name;
        if (cpp_name.find(".cpp") != string::npos) {
            cpp_absolute_path = folder_absolute_path + "/" + cpp_name;
            cpp_relative_path = "input/" + folder_name + "/" + cpp_name;
            Input* newInput = new Input(cpp_name, cpp_absolute_path, cpp_relative_path, folder_absolute_path);
            input_vec.push_back(newInput);
        }
    }
    closedir(dir);
}

void get_stdin_format(string folder_absolute_path) {
    //stdin_format文件绝对路径
    string stdin_format_absolute_path = folder_absolute_path + "/stdin_format.txt";
    ifstream in_file;
    in_file.open(stdin_format_absolute_path, ios::in);
    if (!in_file) {
        exit(-1);
    }
    string str;
    while (in_file >> str) {
        int type = 0;
        int left = 0;
        int right = 0;
        if (str.substr(0, 3) == "int") {
            type = 1;
            int index_1 = str.find(",");
            int index_2 = str.find(")");
            string left_value = "";
            string right_value = "";
            for (int i = 4; i < index_1; i++) {
                left_value += str[i];
            }
            left = stoi(left_value);
            for (int i = index_1 + 1; i < index_2; i++) {
                right_value += str[i];
            }
            right = stoi(right_value);
        }
        else if (str.substr(0, 4) == "char") {
            type = 2;
        }
        else if (str.substr(0, 6) == "string") {
            type = 3;
            int index_1 = str.find(",");
            int index_2 = str.find(")");
            string left_len = "";
            string right_len = "";
            for (int i = 7; i < index_1; i++) {
                left_len += str[i];
            }
            left = stoi(left_len);
            for (int i = index_1; i < index_2; i++) {
                right_len += str[i];
            }
            right = stoi(right_len);
        }
        if (type != 0) {
            Stdin_format* sf = new Stdin_format(type, left, right);
            sf_vec.push_back(sf);
        }
    }
    in_file.close();
}

void make_pair() {
    for (int i = 0; i < input_vec.size() - 1; i++) {
        for (int j = i + 1; j < input_vec.size(); j++) {
            //两两比较，产生C(n,2)个pair
            Output* op = new Output(input_vec[i], input_vec[j]);
            output_vec.push_back(op);
            Judge* judge = new Judge(input_vec[i], input_vec[j], op, sf_vec);
            judge->execute_compare();
        }
    }
}

void make_csv() {
   //等价
    ofstream out_file_equal;
    out_file_equal.open("equal.csv", ios::out);
    out_file_equal << "file1" << ',' << "file2" << endl;
    //不等价
    ofstream out_file_inequal;
    out_file_inequal.open("inequal.csv", ios::out);
    out_file_inequal << "file1" << ',' << "file2" << endl;
    //equal.csv保存等价的OJ程序的相对路径对
    //inequal.csv保存不等价的OJ程序的相对路径对
    for (int i = 0; i < output_vec.size(); ++i) {
        //等价
        if (output_vec[i]->get_result()) {
            out_file_equal << output_vec[i]->get_input_a()->get_relative_path() << ',' << output_vec[i]->get_input_b()->get_relative_path() << endl;
        }
        //不等价
        else if (!output_vec[i]->get_result()) {
            out_file_inequal << output_vec[i]->get_input_a()->get_relative_path() << ',' << output_vec[i]->get_input_b()->get_relative_path() << endl;
        }        
    }
    out_file_equal.close();
    out_file_inequal.close();
}

int main() {
    string input_path = "/home/njucs/input";//input文件夹路径
    string folder_name;//文件夹名
    string folder_absolute_path;//文件夹绝对路径
    DIR* input_dir = opendir(input_path.c_str());
    if (input_dir == NULL) {
        exit(-1);
    }
    dirent* dir;
    while ((dir = readdir(input_dir)) != NULL) {
        folder_name = dir->d_name;
        if (folder_name != ".vscode" && folder_name != "." && folder_name != "..") {
            folder_absolute_path = input_path + "/" + folder_name;
            //得到该文件夹下所有的OJ程序生成Input对象
            get_input(folder_name, folder_absolute_path);
            //得到该文件夹下OJ程序的标准输入样式
            get_stdin_format(folder_absolute_path);
            //对该文件夹下的所有OJ程序两两配对进行等价性判断
            make_pair();
            input_vec.clear();
            sf_vec.clear();
        }
    }
    closedir(input_dir);
    //生成两个csv文件
    make_csv();
    return 0;
}

