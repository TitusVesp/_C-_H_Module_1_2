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
		mod2.AddMenuItem("������ 1, 1 ���i���: ", Zadacha1_1);
		mod2.AddMenuItem("������ 2, 1 ���i���: ", Zadacha1_2);
		mod2.AddMenuItem("������ 3, 1 ���i���: ", Zadacha1_3);
		mod2.AddMenuItem("������ 4, 1 ���i���: ", Zadacha1_4);
	}
	void Show_Lab()
	{
		mod2.ShowMenu();
	}
};