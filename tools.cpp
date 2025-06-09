#include "tools.h"

#include <iostream>
#include <string>

using namespace std;

void clearScreen(){
	cout << "\033[2J\033[1;1H";
}

string textStyle(string text, int color){
	string colorCode = "\033[";
	colorCode += to_string(color);
	colorCode += "m";
	return colorCode + text + "\033[0m";
}

string textStyle(char character, int color){
	string colorCode = "\033[";
	colorCode += to_string(color);
	colorCode += "m";
	return colorCode + character + "\033[0m";
}


