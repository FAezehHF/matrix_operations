// CMakeExercise.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include "CMakeMatrix.h"
// TODO: Reference additional headers your program requires here.


bool is_number(string&);
bool is_double(string&);
string reverseString(string&);
void changeArryaElement(string, int, string, int, int);
bool is_skew_symmetric(string, int);
bool is_normal_symmetric(string, int);
bool is_diagonal(string, int);
bool is_upper_triangular(string, int);
bool is_lower_triangular(string, int);
bool is_identity(string, int);
bool is_nameExsit(string);
void fillArray(string, int, int, string);
void showArray(string);
void deleteArray(string);
void checkArryaElement(string);
void doInverse(string);
void check_symmetric(string);
void check_skew_symmetric(string);
void check_normal_symmetric(string);
void check_identity(string);
void check_diagonal(string);
void check_upper_triangular(string);
void check_lower_triangular(string);
void check_triangular(string);
string commandSeparator(string);
void addMatrix(string);
void runCommands(string, string);
bool Menu();