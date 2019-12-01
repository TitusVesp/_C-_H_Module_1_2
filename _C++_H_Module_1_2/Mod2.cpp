#include "Mod2.h"

void Zadacha1_1()
{
	FILE* f = fopen("D:\\text.txt", "r");
	char text[1000] = { '\0' };
	fread(text, sizeof(char), 1000, f);
	int i = 0;
	bool flag = false;
	while (i <= strlen(text) - 2)
	{
		if (text[i] == '/' && text[i + 1] == '/')
		{
			text[i] = 32;
			text[i + 1] = 32; 
			i += 2;
			while (i <= strlen(text) - 1)
			{
				if (text[i] == 32)
					flag = true;
				if (flag) break;
				if (text[i] == 10)
				{
					cout << endl;
					break;
				}
				cout << text[i];
				text[i] = 32;
				i++;
			}
		}
		if (flag) break;
		i++;
	}
	fclose(f);
	f = fopen("D:\\text.txt", "w");
	fwrite(text, sizeof(char), 1000, f);
	fclose(f);
}

struct Vector
{
	double x, y;

	friend ostream& operator<<(ostream& os, const Vector& dt);
};

ostream& operator<<(ostream& os, const Vector& dt)
{
	os << "(" << dt.x << ',' << dt.y << ")";
	return os;
}

Vector Sum(Vector a, Vector b)
{
	Vector c;
	c.x = a.x + b.x;
	c.y = a.y + b.y;
	return c;
}

double ScalarMultiplication(Vector a, Vector b)
{
	return a.x * b.x + a.y * b.y;
}

double Norm(Vector a)
{
	return sqrt(pow(a.x, 2) + pow(a.y, 2));
}

Vector MultiplicationByScalar(Vector a, double b)
{
	Vector c;
	c.x = b * a.x;
	c.y = b * a.y;
	return c;
}

void OutputConsole(Vector a)
{
	cout << "Here is Vector:" << endl;
	cout << '(' << a.x << ", " << a.y << ')';
	cout << endl << endl;
}

void OutputBin(Vector* a)
{
	ofstream out("Vector.bin");
	out.write((char*)&a, sizeof(Vector));
	out.close();
}

void InputBin(Vector* a)
{
	ifstream input("Vector.bin");
	input.read((char*)&a, sizeof(Vector));
	input.close();
}

void Zadacha1_2()
{
	Vector a = { 1, 2 }, b = { 3, 4 };
	cout << Sum(a, b) << endl;
	cout << ScalarMultiplication(a, b) << endl;
	cout << Norm(a) << endl;
	cout << MultiplicationByScalar(a, 2.2) << endl;
}

int StrToInt(char* s, int& i)
{
	int temp = 0;
	int sign = 0;
	if (s[i] == '-')
	{
		sign = 1;
		i++;
	}
	while ((int)s[i] >= 48 && (int)s[i] <= 57)
	{
		temp += ((int)s[i] - 48);
		temp *= 10;
		i++;
	}
	temp /= 10;
	if (sign == 1)
		temp = -temp;
	return temp;
}

void Zadacha1_3()
{
	FILE* f = fopen("D:\\text.txt", "r");

	char text[1000] = { '\0' };
	fread(text, sizeof(char), 1000, f);
	fclose(f);

	int i = 0;
	int n = StrToInt(text, i);

	int* tmp = new int[n * n];
	int** a = new int* [n];

	for (int ix = 0; ix < n; ix++)
	{
		a[ix] = new int[n];
	}

	int j = 0;
	while (j < n * n)
	{
		i++;
		tmp[j] = StrToInt(text, i);
		j++;
	}

	int itr = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			a[i][j] = tmp[itr];
			itr++;
		}
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (a[i][j] == a[n - 1 - j][n - 1 - i])
			{
				a[i][j] = 0;
				a[n - 1 - j][n - 1 - i] = 0;
			}
		}
	}

	int countR = 0, countC = 0;
	for (i = 0; i < n; i++)
	{
		countR = 0;
		countC = 0;
		for (j = 0; j < n; j++)
		{
			if (a[i][j] == 0) countR++;
			if (a[j][i] == 0) countC++;
		}
		if (countC == 0) cout << "Null column exist" << endl;
		if (countR == 0) cout << "Null row exist" << endl;
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

long long Bin(int n, int k)
{
	if (k > n) return -1;
	if (n == k || k == 0) return 1;
	else
	{
		return Bin(n - 1, k - 1) + Bin(n - 1, k);
	}
}

void Zadacha1_4()
{
	cout << Bin(10, 2) << endl;
}