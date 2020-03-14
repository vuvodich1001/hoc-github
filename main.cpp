#include<iostream>
#include<ctime>
#include"mygame.h"
#include<Windows.h>
#define max 100
using namespace std;
int sl = 3;
void Ve_Tuong_1(int x, int y, int n);
void Ve_Tuong_2(int x, int y, int n);
void tao_hinh_ran(int toadox[], int toadoy[]);
void ve_ran(int toadox[], int toadoy[]);
void them(int a[], int x);
void xoa(int a[], int vt);
void xu_ly_ran(int toadox[], int toadoy[], int x, int y, int a, int b);
void xoa_du_lieu_cu(int toadox[], int toadoy[]);
bool ktchamtuong(int x, int y);
bool ktchamduoi(int toadox[], int toadoy[]);
void hamtaoqua(int& a, int& b);
bool kt_ran_an_qua(int x, int y, int a, int b);
void hamxuyentuong(int& x, int& y, int &xran, int &yran);
void hamtocdo(int diem);
int main()
{

		int luachon;
		gotoXY(70, 5);
		setTextColor(9);
		cout << "\n\n\n\t\t\tMENU GAME<3\n";
		cout << "\n\t\t1. MODE XUYEN TUONG\n";
		cout << "\n\t\t2. MODE BINH THUONG";
		cout << "\t\tNhap lua chon: ";
		cin >> luachon;
		clrscr();
		sl = 3;
		bool gameover = false;
		int a, b;
		setTextColor(9);
		Ve_Tuong_1(5, 2, 100);
		Ve_Tuong_1(5, 25, 100);
		Ve_Tuong_2(5, 2, 25);
		Ve_Tuong_2(100, 2, 25);
		setTextColor(15);
		int toadox[max], toadoy[max];
		tao_hinh_ran(toadox, toadoy);
		ve_ran(toadox, toadoy);
		noCursorType();
		int x = 20, y = 12;
		int check = 2;
		//int i = 2;
		int diem = 0;
		setTextColor(10);
		hamtaoqua(a, b);
				while (gameover == false)
				{
					setTextColor(15);
					gotoXY(0, 0);
					cout << "Diem: " << diem;
					xoa_du_lieu_cu(toadox, toadoy);
					if (check == 0)
					{
						y--;
					}
					else if (check == 1)
					{
						y++;
					}
					else if (check == 2)
					{
						x++;
					}
					else if (check == 3)
					{
						x--;
					}
					if (_kbhit())
					{
						char kitu = _getch();
						if (kitu == 'w' && check != 1)
						{
							check = 0;
						}
						else if (kitu == 's' && check != 0)
						{
							check = 1;
						}
						else if (kitu == 'd' && check != 3)
						{
							check = 2;
						}
						else if (kitu == 'a' && check != 2)
						{
							check = 3;
						}
					}
					if (luachon == 1)
					{
						setTextColor(9);
						hamxuyentuong(x, y, toadox[0], toadoy[0]);
					}
					setTextColor(12);
					xu_ly_ran(toadox, toadoy, x, y, a, b);
					noCursorType();
					setTextColor(15);
					if (toadox[0] == a && toadoy[0] == b)
					{
						diem += 10;
						setTextColor(10);
						hamtaoqua(a, b);
						//i++;
					}
					hamtocdo(diem);
					/*if (i > 15)
					{
						i = 2;
					}*/
					if (luachon == 2)
					{
						bool gameover1 = ktchamtuong(toadox[0], toadoy[0]);
						bool gameover2 = ktchamduoi(toadox, toadoy);
						if (gameover1 == true || gameover2 == true)
						{
							clrscr();
							gotoXY(70, 5);
							setTextColor(13);
							cout << "\n\n\t\t\t\t\tMENU<3\n";
							cout << "\n\t\t\t1. CHOI LAI CON GAME NAY\n";
							cout << "\n\t\t\t2. THOAT GAME ";
							cout << "\t\tNhap lua chon: ";
							setTextColor(15);
							cin >> luachon;
							switch (luachon)
							{
							case 1:
							{
								clrscr();
								main();
							}
							case 2:
							{
								gameover = true;
							}
							}
						}
					}

				}
				
	if (gameover == true)
	{
		clrscr();
		gotoXY(70, 5);
		cout << "\n\n\n\t\t\t\t\tGAME OVER <3";
	}
	return 0;
}
void Ve_Tuong_1(int x, int y, int n)
{
	while (x <= n)
	{
		gotoXY(x, y);
		cout << "-";
		x++;
	}
}
void Ve_Tuong_2(int x, int y, int n)
{
	while (y <= n)
	{
		if (y != 2)
		{
			gotoXY(x, y);
			cout << "|";
		}
		y++;
	}
}
void tao_hinh_ran(int toadox[], int toadoy[])
{
	int x = 20, y = 12;
	for (int i = 0; i < sl; i++)
	{
		toadox[i] = x;
		toadoy[i] = y;
		x--;
	}
}
void ve_ran(int toadox[], int toadoy[])
{
	for (int i = 0; i < sl; i++)
	{
		if (i == 0)
		{
			gotoXY(toadox[i], toadoy[i]);
			cout << (char)79;
		}
		else
		{
			gotoXY(toadox[i], toadoy[i]);
			cout << "o";
		}
	}
}
void them(int a[], int x)
{
	for (int i = sl - 1; i >= 0; i--)
	{
		a[i + 1] = a[i];
	}
	a[0] = x;
	sl++;
}
void xoa(int a[], int vt)
{
	for (int i = vt; i < sl; i++)
	{
		a[i] = a[i + 1];
	}
	sl--;
}
void xu_ly_ran(int toadox[], int toadoy[], int x, int y, int a, int b)
{
	them(toadox, x);
	them(toadoy, y);
	if (kt_ran_an_qua(toadox[0], toadoy[0], a, b) == false)
	{
		xoa(toadox, sl - 1);
		xoa(toadoy, sl - 1);
	}
	else
		sl--;
	ve_ran(toadox, toadoy);
}
void xoa_du_lieu_cu(int toadox[], int toadoy[])
{
	//cout << " " << static_cast<char>(8);
	for (int i = 0; i < sl; i++)
	{
		gotoXY(toadox[i], toadoy[i]);
		cout << " ";
	}
}
bool ktchamtuong(int x, int y)
{
	if ((x >= 5 && x <= 100) && y == 2)
	{
		return true;
	}
	else if ((x >= 5 && x <= 100) && y == 25)
	{
		return true;
	}
	else if ((y >= 2 && y <= 25) && x == 5)
	{
		return true;
	}
	else if ((y >= 2 && y <= 25) && x == 100)
	{
		return true;
	}
	return false;
}
bool ktchamduoi(int toadox[], int toadoy[])
{
	for (int i = 1; i < sl; i++)
	{
		if (toadox[0] == toadox[i] && toadoy[0] == toadoy[i])
		{
			return true;
		}
	}
	return false;
}
void hamtaoqua(int& a, int& b)
{
	srand(time(NULL));
	a = rand() % 94 + 6;
	b = rand() % 22 + 3;
	gotoXY(a, b);
	cout << "$";
}
bool kt_ran_an_qua(int x, int y, int a, int b)
{
	if (x == a && y == b)
	{
		return true;
	}
	return false;
}
void hamxuyentuong(int &x, int &y,int &xran, int &yran)
{
	if(xran==100)
	{ 
		Ve_Tuong_2(100, 2, 25);
		xran = 6;
		x = 6;
	}
	else if (xran == 5)
	{
		Ve_Tuong_2(5, 2, 25);
		xran = 99;
		x = 99;
	}
	else if (yran == 2)
	{
		Ve_Tuong_1(5, 2, 100);
		yran = 24;
		y = 24;
	}
	else if (yran == 25)
	{
		Ve_Tuong_1(5, 25, 100);
		yran = 3;
		y = 3;
	}
}
void hamtocdo(int diem)
{
	if (diem < 50)
	{
		Sleep(150);
	}
	else if (diem >= 50 && diem < 100)
	{
		Sleep(100);
	}
	else if (diem >= 100 && diem < 200)
	{
		Sleep(50);
	}
	else if (diem >= 200)
	{
		Sleep(20);
	}
}