#include "Input.h"
//构造
Input::Input() {}
Input::Input(string _name, string _absolute_path, string _relative_path, string _folder_absolute_path) :
	name(_name),
	absolute_path(_absolute_path),
	relative_path(_relative_path),
	folder_absolute_path(_folder_absolute_path) {}
//get
string Input::get_name() {
	return name;
}
string Input::get_absolute_path() {
	return absolute_path;
}
string Input::get_relative_path() {
	return relative_path;
}
string Input::get_folder_absolute_path() {
	return folder_absolute_path;
}
//set
void Input::set_name(string _name) {
	name = _name;
}
void Input::set_absolute_path(string _absolute_path) {
	absolute_path = _absolute_path;
}
void Input::set_relative_path(string _relative_path) {
	relative_path = _relative_path;
}
void Input::set_folder_absolute_path(string _folder_absolute_path) {
	folder_absolute_path = _folder_absolute_path;
}