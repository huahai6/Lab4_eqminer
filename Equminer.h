#include "Input.h"
#include "Output.h"
#include "Stdin_format.h"
#include "Judge.h"
#include <vector>
#include <dirent.h>
#include <iostream>
#include <fstream>
using namespace std;
//全局变量
vector<Input*> input_vec;
vector<Output*> output_vec;
vector<Stdin_format*> sf_vec;

void get_input(string folder_name, string folder_absolute_path);
void get_stdin_format(string folder_absolute_path);
void make_pair();
void make_csv();