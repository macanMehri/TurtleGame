

#include <iostream>
using namespace std;
// تابع نمایش آرایه، در صورت پایین بودن قلم ستاره و در غیر این صورت اسپیس چاپ کند
void ShowArray(int l[20][20], char sh)
{
	for (int i = 0; i < 20; i++)	
	{
		for (int j = 0; j < 20; j++)	
		{
			if (l[i][j] == 1)
				cout << sh;
			else
				cout << ' ';
		}
		cout << '\n';
	}
}

int main()
{
	int floor[20][20] = { 0 };
	
	int x = 0;            //مختصات یا طول و عرض شکل
	int y = 0;
	//کاراکتر رسم
	char shape;
	//تعریف دستور دریافتی از کاربر
	int order = 0;
	int pen = 1;         // یک معادل پایین بودن قلم و صفر معادل بال بودن قلم است
	int direction = 1;   //یک برای حرکت به راست و دو حرکت به پایین و سه حرکت به چپ و چهار حرکت به بالا
	int move = 0;
	cout << "Please enter a character to draw path: ";
	// دریافت یک کاراکتر از کاربر برای رسم راه پیموده شده توسط لاکپشت
	cin >> shape;
	cout << "1 Pen up\n2 Pen down\n3 Turn right\n4 Turn left\n5 Move forward n spaces\n6 Display the path\n9 Quit!\n";
	while (order != 9)
	{	
		cin >> order;          //دریافت دستور از کاربر
		switch (order)
		{
		case 1:
			pen = 0;           // pen up
			break;
		case 2:
			pen = 1;           // pen down
			break;
		case 3:
			if (direction == 4)
				direction = 1;       // turn right
			else
				direction++;
			break;
		case 4:
			if (direction == 1)
				direction = 4;       // turn left
			else
				direction--;
			break;
		case 5:
			cout << "Please enter number to moves: ";        // move forward n moves
			cin >> move;
			if (direction == 1)
			{
				if (pen == 1)
				{
					for (int i = 0; i <= move; i++)
						floor[y][x + i] = pen;
				}
				else
				{
					for (int i = 1; i <= move; i++)
						floor[y][x + i] = pen;
				}
				x += move;
			}
			else if (direction == 2)
			{
				if (pen == 1)
				{
					for (int i = 0; i <= move; i++)
						floor[y + i][x] = pen;
				}
				else
				{
					for (int i = 1; i <= move; i++)
						floor[y + i][x] = pen;
				}
				y += move;
			}
			else if (direction == 3)
			{
				if (pen == 1)
				{
					for (int i = 0; i <= move; i++)
						floor[y][x - i] = pen;
				}
				else
				{
					for (int i = 1; i <= move; i++)
						floor[y][x - i] = pen;
				}
				x -= move;
			}
			else
			{
				if (pen == 1)
				{
					for (int i = 0; i <= move; i++)
						floor[y - i][x] = pen;
				}
				else
				{
					for (int i = 1; i <= move; i++)
						floor[y - i][x] = pen;
				}
				y -= move;
			}			
			break;
		case 6:
			system("cls");
			ShowArray(floor ,shape);		  // Display array	
			break;
		}
	}


	getchar();
}

