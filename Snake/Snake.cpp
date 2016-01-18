// Nexus Snake.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <Windows.h>
#include <MMSystem.h>
#include <conio.h>
#include <cstdlib>
#pragma comment(lib,"winmm.lib")
using namespace std;
int cul = 90;
int temp;
void gotoxy(int x, int y)
{
	COORD p = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
};
void ClearScreen()
{
	HANDLE                     hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD                      count;
	DWORD                      cellCount;
	COORD                      homeCoords = { 0, 0 };

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE) return;

	/* Get the number of cells in the current buffer */
	if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
	cellCount = csbi.dwSize.X *csbi.dwSize.Y;

	/* Fill the entire buffer with spaces */
	if (!FillConsoleOutputCharacter(
		hStdOut,
		(TCHAR) ' ',
		cellCount,
		homeCoords,
		&count
		)) return;

	/* Fill the entire buffer with the current colors and attributes */
	if (!FillConsoleOutputAttribute(
		hStdOut,
		csbi.wAttributes,
		cellCount,
		homeCoords,
		&count
		)) return;

	/* Move the cursor home */
	SetConsoleCursorPosition(hStdOut, homeCoords);
}
struct desenat
{
	char colt_drp_sus = 187;
	char linie_orizontala = 205;
	char colt_drp_jos = 188;
	char colt_stg_sus = 201;
	char colt_stg_jos = 200;
	char linie_verticala = 186;
	char spatiu = 32;
	char cap = ' ';
	char coada = ' ';
	char enter = 13;
	char tab = 9;
	char del = 127;
	char bks = 8;
	char mancare = '@';
};
class highscore
{
private: int i, j; string scor, str;desenat brush;
public:
	struct top
	{
		int place = 1;
		string name = " ";
		int score = 0;

	};
	top tp[9];
	void get_highscore()
	{
		ifstream file("highscore.txt");
		while (getline(file, str))
		{
			if (str[0] == 'n')
			{
				tp[str[1] - '0'].place = str[1] - '0';
				getline(file, tp[str[1] - '0'].name);
			}
			if (str[0] == 's')
			{
				tp[str[1] - '0'].place = str[1] - '0';
				getline(file, scor);
				tp[str[1] - '0'].score = stoi(scor);
			}
		}

	};
	void show_highscore()
	{
		ifstream file("highscore.txt");
		ClearScreen();
		get_highscore();
		gotoxy(25, 5);
		cout << "Highscores:";
		for (i = 1;i <= 8;i++)
		{
			gotoxy(22, 7 + i * 2);
			if (tp[i].name != " ")
				cout << tp[i].place << ")" << brush.spatiu << tp[i].name << ":" << tp[i].score;
			else cout << i << ")";
		}
		gotoxy(47, 31);
		cout << "Press \"b\" to return.";
		
	};
	void update_highscore(int new_score, string new_name)
	{
		ifstream file("highscore.txt");
		get_highscore();
		if (new_score >= tp[8].score)
		{
			for (i = 8;i >= 1;i--)
			{
				if (new_score >= tp[i].score)
				{
					tp[i] = tp[i - 1];

				}
				else break;
			}

			this->tp[i + 1].name = new_name;
			this->tp[i + 1].score = new_score;
			this->tp[i + 1].place = i;
			for (j = i + 1;j <= 8;j++)
				this->tp[j].place++;


			ofstream fout("highscore.txt");

			for (i = 1;i <= 8;i++)
			{
				fout << 'n' << i << endl;
				fout << this->tp[i].name << endl;
				fout << 's' << this->tp[i].place << endl;
				fout << tp[i].score << endl;

			}
			fout.close();

		}

	}
};
class Start_Menu
{
	desenat d;
public:
	void show_start_menu()
	{
		// Obtain the Console handle
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Obtain the Console handle

		PCONSOLE_FONT_INFOEX lpConsoleCurrentFontEx = new CONSOLE_FONT_INFOEX();

		// set the size of the CONSOLE_FONT_INFOEX
		lpConsoleCurrentFontEx->cbSize = sizeof(CONSOLE_FONT_INFOEX);

		// get the current value
		GetCurrentConsoleFontEx(hConsole, 0, lpConsoleCurrentFontEx);

		// set size to be 8x18, the default size is 8x16
		lpConsoleCurrentFontEx->dwFontSize.X = 8;
		lpConsoleCurrentFontEx->dwFontSize.Y = 16;

		// submit the settings
		SetCurrentConsoleFontEx(hConsole, 0, lpConsoleCurrentFontEx);

		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		int col = 15;
		FlushConsoleInputBuffer(hConsole);
		SetConsoleTextAttribute(hConsole, col);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), col);

		ClearScreen();
		gotoxy(17, 3);
		cout<< d.colt_stg_sus << d.linie_orizontala << d.linie_orizontala << d.linie_orizontala << d.linie_orizontala << d.linie_orizontala << d.linie_orizontala << d.linie_orizontala << d.linie_orizontala << d.linie_orizontala << d.linie_orizontala << d.linie_orizontala << d.linie_orizontala << d.linie_orizontala << d.linie_orizontala << d.linie_orizontala << d.linie_orizontala << d.linie_orizontala << d.linie_orizontala << d.linie_orizontala << d.linie_orizontala << d.linie_orizontala << d.linie_orizontala << d.linie_orizontala << d.linie_orizontala << d.linie_orizontala << d.linie_orizontala << d.linie_orizontala << d.linie_orizontala << d.linie_orizontala << d.linie_orizontala << d.linie_orizontala << d.linie_orizontala << d.linie_orizontala << d.linie_orizontala << d.linie_orizontala << d.linie_orizontala << d.colt_drp_sus;
		for (int i = 4;i <= 27;i++)
		{
			gotoxy(17, i);
			cout << d.linie_verticala;
			gotoxy(54, i);
			cout << d.linie_verticala;
		}
		gotoxy(17, 28);
		cout << d.colt_stg_jos;
		for (int i = 21; i <= 56; i++)
		{
			cout << d.linie_orizontala;
		}
		cout << d.colt_drp_jos;
		highscore h;
		gotoxy(24, 6);
		cout << "WELCOME TO NEXUS-SNAKE";
		gotoxy(30, 13);
		cout << "[P]LAY";
		gotoxy(30, 16);
		cout << "[H]IGHSCORES";
		gotoxy(30, 19);
		cout << "E[X]IT";
	}
};
class play
{
	HANDLE handleIn;
	HANDLE handleOut;
	COORD KeyWhere;
	COORD MouseWhere;
	COORD EndWhere;
	INPUT_RECORD recordIn;
	DWORD NumRead;

	struct cioco {
		bool mancare=0;
		int culoare=90;
	};
	cioco lolz;
	desenat brush;
	Start_Menu sm;
	string new_name;


	bool alive;
	highscore h;
	int v1=0, v2=0;
	unsigned int new_score;
	void enter_name()
	{
		gotoxy(17, 14);
		cout << "Enter your name: ";
		cin >> new_name;
		gotoxy(17, 14);
		cout << "                                                                                                                                      ";
	}

	void game_over(string name,unsigned int scor)
	{
		HANDLE  hConsole;
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		int col = 15;
		FlushConsoleInputBuffer(hConsole);
		SetConsoleTextAttribute(hConsole, col);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), col);


		ClearScreen();
		gotoxy(25, 7);
		cout << "GAME OVER";
		gotoxy(15, 9);
		cout << name << " Score: " << scor;
		h.update_highscore(new_score, new_name);
		Sleep(3000);
		ClearScreen();
		sm.show_start_menu();	
	}
public:
	void joc()
	{
		struct position
		{
			int x = 0;
			int y = 0;
			int culoare;
		};
		struct snake
		{
			position  head;
			position  tail[5000];
			unsigned int lungime = 2;
			unsigned int directie = 3;
		};
		snake snk;
		// Obtain the Console handle
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Obtain the Console handle

		PCONSOLE_FONT_INFOEX lpConsoleCurrentFontEx = new CONSOLE_FONT_INFOEX();

		// set the size of the CONSOLE_FONT_INFOEX
		lpConsoleCurrentFontEx->cbSize = sizeof(CONSOLE_FONT_INFOEX);

		// get the current value
		GetCurrentConsoleFontEx(hConsole, 0, lpConsoleCurrentFontEx);

		// set size to be 8x18, the default size is 8x16
		lpConsoleCurrentFontEx->dwFontSize.X = 12;
		lpConsoleCurrentFontEx->dwFontSize.Y = 12;

		// submit the settings
		SetCurrentConsoleFontEx(hConsole, 0, lpConsoleCurrentFontEx);

		

		alive = 1;
		enter_name();
		h.get_highscore();
		new_score = 0;
		gotoxy(17, 3);
		cout << "Player: " <<  new_name << "; Score: " <<  new_score << "; " << "Highscore: " <<  h.tp[1].score << ";" << endl;
		gotoxy(4, 5);
		cout << brush.colt_stg_sus;
		for (int i = 5;i <= 65;i++)
			cout << brush.linie_orizontala;
		cout << brush.colt_drp_sus;
		for (int i = 6;i <= 29;i++)
		{
			gotoxy(4, i);
			cout << brush.linie_verticala;
			gotoxy(66, i);
			cout << brush.linie_verticala;
		}

		gotoxy(4, 30);

		cout << brush.colt_stg_jos;
		for (int i = 21;i <= 81;i++)
			cout << brush.linie_orizontala;
		cout << brush.colt_drp_jos;
		snk.head.x = 8;
		snk.head.y = 16;
		snk.head.culoare = 200;
		snk.tail[0].x = 6;
		snk.tail[0].y = 16;
		snk.tail[0].culoare = 90;
		snk.tail[1].x = 7;
		snk.tail[1].y = 16;
		snk.tail[1].culoare = 17;

		gotoxy(snk.head.x, snk.head.y);
		cout << brush.cap;


		gotoxy(snk.tail[1].x, snk.tail[1].y);
		cout << brush.coada;
		gotoxy(snk.tail[0].x, snk.tail[0].y);
		cout << brush.coada;
		
		while (alive)
		{
			HANDLE  hConsole;
			hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			int col = 90;
			FlushConsoleInputBuffer(hConsole);
			SetConsoleTextAttribute(hConsole, col);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), col);
			
				if (_kbhit())
				{
					int command = _getch();
					
					if (_kbhit())
					{
						command = _getch();
						if (command == 77)
						{
							if ( snk.directie != 9)
								 snk.directie = 3;
						}
						if (command == 75)
						{
							if ( snk.directie != 3)
								 snk.directie = 9;
						}
						if (command == 72)
						{
							if ( snk.directie != 6)
								 snk.directie = 12;
						}
						if (command == 80)
						{
							if ( snk.directie != 12)
								 snk.directie = 6;
						}

					}


					if (command == 77)
					{
						if( snk.directie!=9)
						 snk.directie = 3;
					}
					if (command == 75)
					{
						if ( snk.directie != 3)
						 snk.directie = 9;
					}
					if (command == 72)
					{
						if ( snk.directie != 6)
						 snk.directie = 12;
					}
					if (command == 80)
					{
						if ( snk.directie != 12)
						 snk.directie = 6;
					}
				}


			for (unsigned int i = 0;i < snk.lungime;i++)
				if (snk.head.x == snk.tail[i].x && snk.head.y == snk.tail[i].y)
				{
					alive = 0;
					snk.directie = 3;
					snk.lungime = 2;
					lolz.mancare = 0;
					snk.head.x = 0;
					snk.head.y = 0;
					snk.tail[0].x = 0;
					snk.tail[0].y = 0;
					snk.tail[1].x = 0;
					snk.tail[1].y = 0;
					game_over( new_name,  new_score);
					return;
				}

			if ( snk.directie == 3)
			{
				if (snk.head.x <= 64)
				{
					hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					col = 15;
					FlushConsoleInputBuffer(hConsole);
					SetConsoleTextAttribute(hConsole, col);

					gotoxy(snk.tail[0].x, snk.tail[0].y);
					cout << brush.spatiu;

	

					for (unsigned int i = 0;i < snk.lungime;i++)
					{
						if (i >= snk.lungime - 1)
						{
							snk.tail[i].x = snk.head.x;
							snk.tail[i].y = snk.head.y;
							
						}
						else
						{
							snk.tail[i].x = snk.tail[i + 1].x;
							snk.tail[i].y = snk.tail[i + 1].y;
						}
							
					}
					for (int i = 0;i < snk.lungime;i++)
					{
						hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
						col = snk.tail[i].culoare;
						FlushConsoleInputBuffer(hConsole);
						SetConsoleTextAttribute(hConsole, col);

						gotoxy(snk.tail[i].x, snk.tail[i].y);
						cout << brush.coada;
					}


	

					snk.head.x++;
					hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					col = snk.head.culoare;
					FlushConsoleInputBuffer(hConsole);
					SetConsoleTextAttribute(hConsole, col);
					gotoxy(snk.head.x, snk.head.y);
					cout << brush.cap;


					hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					col = 15;
					FlushConsoleInputBuffer(hConsole);
					SetConsoleTextAttribute(hConsole, col);
				}
				else
				{
					hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					col = 15;
					FlushConsoleInputBuffer(hConsole);
					SetConsoleTextAttribute(hConsole, col);
					gotoxy(snk.tail[0].x, snk.tail[0].y);
					cout << ' ';
					hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					col = snk.head.culoare;
					FlushConsoleInputBuffer(hConsole);
					SetConsoleTextAttribute(hConsole, col);
					gotoxy(snk.head.x, snk.head.y);
					cout << ' ';

					for (unsigned int i = 0;i < snk.lungime;i++)
					{
						if (i < snk.lungime - 1)
						{
							snk.tail[i].x = snk.tail[i + 1].x;
							snk.tail[i].y = snk.tail[i + 1].y;
						}
						else
						{
							snk.tail[i].x = snk.head.x;
							snk.tail[i].y = snk.head.y;
						}
							
					}

					snk.head.x = 5;


					hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					col = 15;
					FlushConsoleInputBuffer(hConsole);
					SetConsoleTextAttribute(hConsole, col);
					
				}

			}

			if ( snk.directie == 6)
			{
				if (snk.head.y <= 28)
				{
					hConsole;
					hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					col = 15;
					FlushConsoleInputBuffer(hConsole);
					SetConsoleTextAttribute(hConsole, col);

					gotoxy(snk.tail[0].x, snk.tail[0].y);
					cout << brush.spatiu;

					for (unsigned int i = 0;i < snk.lungime;i++)
					{
						if (i >= snk.lungime - 1)
						{
							snk.tail[i].x = snk.head.x;
							snk.tail[i].y = snk.head.y;

						}
						else
						{
							snk.tail[i].x = snk.tail[i + 1].x;
							snk.tail[i].y = snk.tail[i + 1].y;
						}

					}
					for (int i = 0;i < snk.lungime;i++)
					{
						hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
						col = snk.tail[i].culoare;
						FlushConsoleInputBuffer(hConsole);
						SetConsoleTextAttribute(hConsole, col);

						gotoxy(snk.tail[i].x, snk.tail[i].y);
						cout << brush.coada;
					}

					hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					col = snk.head.culoare;
					FlushConsoleInputBuffer(hConsole);
					SetConsoleTextAttribute(hConsole, col);
					snk.head.y++;
					gotoxy(snk.head.x, snk.head.y);
					cout << brush.cap;


				}
				else
				{

					hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					col = 15;
					FlushConsoleInputBuffer(hConsole);
					SetConsoleTextAttribute(hConsole, col);
					gotoxy(snk.tail[0].x, snk.tail[0].y);
					cout << ' ';
					hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					col = snk.head.culoare;
					FlushConsoleInputBuffer(hConsole);
					SetConsoleTextAttribute(hConsole, col);
					gotoxy(snk.head.x, snk.head.y);
					cout << ' ';

					for (unsigned int i = 0;i < snk.lungime;i++)
					{
						if (i < snk.lungime - 1)
						{
							snk.tail[i].x = snk.tail[i + 1].x;
							snk.tail[i].y = snk.tail[i + 1].y;
						}
						else
						{
							snk.tail[i].x = snk.head.x;
							snk.tail[i].y = snk.head.y;
						}

					}

					snk.head.y = 6;


					hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					col = 15;
					FlushConsoleInputBuffer(hConsole);
					SetConsoleTextAttribute(hConsole, col);


				}
			}
			if ( snk.directie == 9)
			{
				if (snk.head.x >= 6)
				{
					hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					col = 15;
					FlushConsoleInputBuffer(hConsole);
					SetConsoleTextAttribute(hConsole, col);
					gotoxy(snk.tail[0].x, snk.tail[0].y);
					cout << brush.spatiu;



					for (unsigned int i = 0;i < snk.lungime;i++)
					{
						if (i < snk.lungime - 1)
						{
							snk.tail[i].x = snk.tail[i + 1].x;
							snk.tail[i].y = snk.tail[i + 1].y;
						}
						else
						{
							snk.tail[i].x = snk.head.x;
							snk.tail[i].y = snk.head.y;
						}

					}
					for (int i = 0;i < snk.lungime;i++)
					{
						hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
						col = snk.tail[i].culoare;
						FlushConsoleInputBuffer(hConsole);
						SetConsoleTextAttribute(hConsole, col);

						gotoxy(snk.tail[i].x, snk.tail[i].y);
						cout << brush.coada;
					}


					hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					col = snk.head.culoare;
					FlushConsoleInputBuffer(hConsole);
					SetConsoleTextAttribute(hConsole, col);
					gotoxy(snk.head.x-1, snk.head.y);
					cout << brush.cap;


					snk.head.x--;
				}
				else
				{
					hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					col = 15;
					FlushConsoleInputBuffer(hConsole);
					SetConsoleTextAttribute(hConsole, col);
					gotoxy(snk.tail[0].x, snk.tail[0].y);
					cout << ' ';
					hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					col = snk.head.culoare;
					FlushConsoleInputBuffer(hConsole);
					SetConsoleTextAttribute(hConsole, col);
					gotoxy(snk.head.x, snk.head.y);
					cout << ' ';

					for (unsigned int i = 0;i < snk.lungime;i++)
					{
						if (i < snk.lungime - 1)
						{
							snk.tail[i].x = snk.tail[i + 1].x;
							snk.tail[i].y = snk.tail[i + 1].y;
						}
						else
						{
							snk.tail[i].x = snk.head.x;
							snk.tail[i].y = snk.head.y;
						}

					}

					snk.head.x = 65;


					hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					col = 15;
					FlushConsoleInputBuffer(hConsole);
					SetConsoleTextAttribute(hConsole, col);


				}

			}

			if ( snk.directie == 12)
			{
				if (snk.head.y >= 7)
				{
					hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					col = 15;
					FlushConsoleInputBuffer(hConsole);
					SetConsoleTextAttribute(hConsole, col);

					gotoxy(snk.tail[0].x, snk.tail[0].y);
					cout << brush.spatiu;

					for (unsigned int i = 0;i < snk.lungime;i++)
					{
						if (i < snk.lungime - 1)
						{
							snk.tail[i].x = snk.tail[i + 1].x;
							snk.tail[i].y = snk.tail[i + 1].y;
						}
						else
						{
							snk.tail[i].x = snk.head.x;
							snk.tail[i].y = snk.head.y;
						}

					}
					for (int i = 0;i < snk.lungime;i++)
					{
						hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
						col = snk.tail[i].culoare;
						FlushConsoleInputBuffer(hConsole);
						SetConsoleTextAttribute(hConsole, col);

						gotoxy(snk.tail[i].x, snk.tail[i].y);
						cout << brush.coada;
					}

					hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					col = snk.head.culoare;
					FlushConsoleInputBuffer(hConsole);
					SetConsoleTextAttribute(hConsole, col);
					gotoxy(snk.head.x, snk.head.y -1);
					cout << brush.cap;
					snk.head.y--;

				}
				else
				{

					hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					col = 15;
					FlushConsoleInputBuffer(hConsole);
					SetConsoleTextAttribute(hConsole, col);
					gotoxy(snk.tail[0].x, snk.tail[0].y);
					cout << ' ';
					hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					col = snk.head.culoare;
					FlushConsoleInputBuffer(hConsole);
					SetConsoleTextAttribute(hConsole, col);
					gotoxy(snk.head.x, snk.head.y);
					cout << ' ';

					for (unsigned int i = 0;i < snk.lungime;i++)
					{
						if (i < snk.lungime - 1)
						{
							snk.tail[i].x = snk.tail[i + 1].x;
							snk.tail[i].y = snk.tail[i + 1].y;
						}
						else
						{
							snk.tail[i].x = snk.head.x;
							snk.tail[i].y = snk.head.y;
						}

					}

					snk.head.y = 29;


					hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					col = 15;
					FlushConsoleInputBuffer(hConsole);
					SetConsoleTextAttribute(hConsole, col);
				}

			}




			if (lolz.mancare == 0)
			{
				randomizer:
				v1 = rand() % 60 + 5;    
				v2 = rand() % 23 + 6;  
				gotoxy(v1, v2);
				for (int i = 0;i < snk.lungime;i++)
				{
					if ((v1 == snk.tail[i].x && v2 == snk.tail[i].y) || (snk.head.x == v1 && snk.head.y == v2))
						goto randomizer;
				}
				hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				lolz.culoare = rand() % 13 + 1;
				FlushConsoleInputBuffer(hConsole);
				SetConsoleTextAttribute(hConsole, lolz.culoare);

				cout << brush.mancare;
				lolz.mancare = 1;
			}
		
			if (snk.head.x == v1 && snk.head.y == v2)
			{
				int lentg =  new_name.length();
				 new_score++;
				lolz.mancare = 0;
				gotoxy(17 + 17 + lentg, 3);
				hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				int col = 15;
				FlushConsoleInputBuffer(hConsole);
				SetConsoleTextAttribute(hConsole, col);
				 snk.lungime++;
				 snk.tail[snk.lungime - 1].culoare = lolz.culoare*16;

				cout <<  new_score;
			}

			
			Sleep(30);
		}
	}
};
class meniuri
{
public: highscore h; Start_Menu s;play p;
		desenat d;
		void switch_menu()
		{
			char k = 1;
			while (k)
			{
				k=_getch();
				if (k == 'x')
				{
					ClearScreen();
					cout << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n';
					cout << d.tab << d.spatiu  << d.spatiu << d.linie_verticala << d.spatiu << d.spatiu << d.spatiu << d.spatiu << d.spatiu << d.spatiu << d.spatiu << d.spatiu << d.spatiu << d.spatiu << d.spatiu << d.spatiu  << d.spatiu << d.spatiu << d.spatiu << "Thanks for playing!" << d.tab << d.spatiu << d.spatiu << d.spatiu << d.spatiu << d.spatiu << d.spatiu << d.spatiu << d.spatiu << d.spatiu << d.spatiu << d.spatiu << d.linie_verticala;
					cout << '\n' << '\n';
					for (int i = 4;i >= 0;i--)
					{
						cout << d.tab  << d.spatiu << d.spatiu << d.spatiu << d.spatiu << d.spatiu << d.spatiu << d.spatiu << d.spatiu << d.spatiu << d.spatiu << d.spatiu << d.spatiu << d.spatiu << d.spatiu << d.spatiu << i << " seconds to self-destruct"<<'\r';
						Sleep(1000);
					}
					Sleep(1500);
					cout<< d.tab << d.spatiu << d.spatiu << d.spatiu << d.spatiu << d.spatiu << d.spatiu << d.spatiu << d.spatiu << d.spatiu << d.spatiu << d.spatiu << d.spatiu << d.spatiu << d.spatiu << d.spatiu  << "    jk, got you haha          " << '\r';
					Sleep(1500);
					exit(0);
				}
				if (k == 'b')
				{
					ClearScreen();
					s.show_start_menu();
					break;
				}
				if (k == 'h')
				{
					ClearScreen();
					h.show_highscore();
					break;
				}
				if (k == 'p')
				{
					ClearScreen();
					p.joc();
					break;
				}
			}
		};
};

int main()
{
	//// Obtain the Console handle
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Obtain the Console handle

	PCONSOLE_FONT_INFOEX lpConsoleCurrentFontEx = new CONSOLE_FONT_INFOEX();

	//// set the size of the CONSOLE_FONT_INFOEX
	lpConsoleCurrentFontEx->cbSize = sizeof(CONSOLE_FONT_INFOEX);

	//// get the current value
	GetCurrentConsoleFontEx(hConsole, 0, lpConsoleCurrentFontEx);

	//// set size to be 8x18, the default size is 8x16
	lpConsoleCurrentFontEx->dwFontSize.X = 8;
	lpConsoleCurrentFontEx->dwFontSize.Y = 16;

	//// submit the settings
	SetCurrentConsoleFontEx(hConsole, 0, lpConsoleCurrentFontEx);




	PlaySoundA("C:\\Users\\Cristian Simionescu\\Downloads\\Jon_Henrik_-_Daniel_39_s_jojk_10_MIN.wav", NULL, SND_FILENAME | SND_ASYNC);
	highscore h;
	Start_Menu s;
	meniuri m;
	play p;
	bool work = 1;
	s.show_start_menu();
	while(work)
	m.switch_menu();

	//highscore h;
	//h.update_highscore(56000,"Radulescu");
	//h.get_highscore();
	//for (int i = 1;i < 8;i++)
	//{
	//	cout << h.tp[i].place << ") " << h.tp[i].name << "        " << h.tp[i].score << endl;
	//}


	
	system("pause");
}



/*
PlaySoundA("C:\\Users\\Cristian Simionescu\\Desktop\\forsenSS.wav", NULL, SND_FILENAME | SND_ASYNC);
Sleep(385000);
*/