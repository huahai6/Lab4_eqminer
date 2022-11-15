#include "Output.h"
//构造
Output::Output() :
	input_a(NULL),
	input_b(NULL) ,
	result(false),
	manual(false) {}
Output::Output(Input* _input_a, Input* _input_b) :
	input_a(_input_a), 
	input_b(_input_b),
	result(false),
	manual(false) {}
//get
Input* Output::get_input_a() {
	return input_a;
}
Input* Output::get_input_b() {
	return input_b;
}
bool Output::get_result() {
	return result;
}
bool Output::get_manual() {
	return manual;
}
//set
void Output::set_result(bool _result) {
	result = _result;
}
void Output::set_manual(bool _manual) {
	manual = _manual;
}
