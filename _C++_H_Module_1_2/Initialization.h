#pragma once
#include "OOP_Menu.h"
#include "Mod2.h"

class Init
{
private:
	Menu mod2;
public:

	Init()
	{
		mod2.AddMenuItem("Задача 1, 1 Варiант: ", Zadacha1_1);
		mod2.AddMenuItem("Задача 2, 1 Варiант: ", Zadacha1_2);
		mod2.AddMenuItem("Задача 3, 1 Варiант: ", Zadacha1_3);
		mod2.AddMenuItem("Задача 4, 1 Варiант: ", Zadacha1_4);
	}
	void Show_Lab()
	{
		mod2.ShowMenu();
	}
};