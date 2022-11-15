#include "Stdin_format.h"
//构造
Stdin_format::Stdin_format() :
	type(0),
	left(0),
	right(0) {}
Stdin_format::Stdin_format(int _type, int _left, int _right) :
	type(_type),
	left(_left),
	right(_right) {}
//get
int Stdin_format::get_type() {
	return type;
}
int Stdin_format::get_left() {
	return left;
}
int Stdin_format::get_right() {
	return right;
}
//set
void Stdin_format::set_type(int _type) {
	type = _type;
}
void Stdin_format::set_left(int _left) {
	left = _left;
}
void Stdin_format::set_right(int _right) {
	right = _right;
}
