// _C++_H_Module_1_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Initialization.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "ukr");
	Init start;

	start.Show_Lab();
	return 0;
}

