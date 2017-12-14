#include <stdio.h>
#include <vector>
#include <iostream>
#include <conio.h>
using namespace std;

void game();
void layout();
void printLayout();
void getPos();
const int horiline = 20;
vector<vector<char>> row;


int main()
{
	game();
	system("pause");
	return 0;
}

void layout()
{
	for (int i = 0; i < 6; i++)
	{
		vector<char>col;
		for (int j = 0; j < 20; j++)
		{
			col.push_back(horiline);
		}
		row.push_back(col);
	}

	//creating the empty layout
	for (std::vector<std::vector<int>>::size_type i = 0; i < row.size(); i++)
	{

		for (std::vector<int>::size_type j = 0; j < row[i].size(); j++)
		{
			row[i][j] = '.';
		}
	}

	//randomizing the elements
	for (std::vector<std::vector<int>>::size_type i = 0; i < 1; i++)
	{
		for (std::vector<int>::size_type j = 0; j < 1; j++)
		{
				if (row[i][j] = '.')
				{
					int rand1 = rand() % row.size();
					int rand2 = rand() % row[i].size();
					int playerRand1 = rand() % row.size();
					int playerRand2 = rand() % row[i].size();
					row[rand1][rand2] = 'X';
					row[playerRand1][playerRand2] = '@';
					for (int count = 0; count < 8; count++)
					{
						int rand1 = rand() % row.size();
						int rand2 = rand() % row[i].size();
						row[rand1][rand2] = 'T';
					}
				}

			}
	}

//print out the layout
	for (std::vector<std::vector<int>>::size_type i = 0; i < row.size(); i++)
	{

		for (std::vector<int>::size_type j = 0; j < row[i].size(); j++)
		{
			std::cout << row[i][j];
		}
		std::cout << std::endl;
	}
}

void printLayout()
{
	for (std::vector<std::vector<int>>::size_type i = 0; i < row.size(); i++)
	{

		for (std::vector<int>::size_type j = 0; j < row[i].size(); j++)
		{
			std::cout << row[i][j];
		}
		std::cout << std::endl;
	}
}

void getPos()
{
	int gameover = 1;
	int playerPos1 = 0;
	int	playerPos2 = 0;
	int playerPos1temp;
	int playerPos2Temp;
	for (std::vector<std::vector<int>>::size_type i = 0; i < row.size(); i++)
	{

		for (std::vector<int>::size_type j = 0; j < row[i].size(); j++)
		{
			if (row[i][j] == '@')
			{
				playerPos1 = i;
				playerPos2 = j;
			}
		}
	}

	while (gameover != 0)
	{
		char dir;
		cin >> dir;
		switch (dir)
		{
		case 'w':
			if (playerPos1 == 0)
			{
				row[playerPos1 + 5][playerPos2] = row[playerPos1][playerPos2];
				row[playerPos1][playerPos2] = '.';
				playerPos1 = playerPos1 + 5;
				playerPos2 = playerPos2;
				system("cls");
				printLayout();
				break;
			}
			else if (row[playerPos1][playerPos2] == 'X')
			{
				cout << "Congratulations!" << endl;
				cout << "Game over! " << endl;
				gameover = 1;
				break;
				//exit(0);
			}
			else if (row[playerPos1][playerPos2] == 'T')
			{
				cout << "Game over! " << endl;
				gameover = 1;
				break;
				//exit(0);
			}
			else
			{
				//playerPos1 = playerPos1temp;
				row[playerPos1 - 1][playerPos2] = row[playerPos1][playerPos2];
				row[playerPos1][playerPos2] = '.';
				playerPos1 = playerPos1 - 1;
				playerPos2 = playerPos2;
				system("cls");
				printLayout();
				break;
			}
		case 's':
			if (playerPos1 == 5)
			{
				row[playerPos1-5][playerPos2] = row[playerPos1][playerPos2];
				row[playerPos1][playerPos2] = '.';
				playerPos1 = 0;
				playerPos2 = playerPos2;
				system("cls");
				printLayout();
				break;
			}
			else if (row[playerPos1 + 1][playerPos2] == 'X')
			{
				cout << "Congratulations!" << endl;
				cout << "Game over! " << endl;
				gameover = 1;
				break;
			}
			else if (row[playerPos1 + 1][playerPos2] == 'T')
			{
				cout << "Game over! " << endl;
				gameover = 1;
				break;
				//exit(0);
			}
			else
			{
				row[playerPos1 + 1][playerPos2] = row[playerPos1][playerPos2];
				row[playerPos1][playerPos2] = '.';
				playerPos1 = playerPos1 + 1;
				playerPos2 = playerPos2;
				system("cls");
				printLayout();
				break;
			}
		case 'a':
			if (playerPos2 == 0)
			{
				row[playerPos1][playerPos2 + 19] = row[playerPos1][playerPos2];
				row[playerPos1][playerPos2] = '.';
				playerPos1 = playerPos1;
				playerPos2 = playerPos2 + 19;
				system("cls");
				printLayout();
				break;
			}
			else if (row[playerPos1][playerPos2 - 1] == 'X')
			{
				cout << "Congratulations!" << endl;
				cout << "Game over! " << endl;
				gameover = 1;
				break;
			}
			else if (row[playerPos1][playerPos2 - 1] == 'T')
			{
				cout << "Game over! " << endl;
				gameover = 1;
				break;
			}
			else
			{
				row[playerPos1][playerPos2 - 1] = row[playerPos1][playerPos2];
				row[playerPos1][playerPos2] = '.';
				playerPos1 = playerPos1;
				playerPos2 = playerPos2 - 1;
				system("cls");
				printLayout();
				break;
			}
		case 'd':
			if (playerPos2 == 19)
			{
				row[playerPos1][playerPos2 - 19] = row[playerPos1][playerPos2];
				row[playerPos1][playerPos2] = '.';
				playerPos1 = playerPos1;
				playerPos2 = playerPos2 - 19;
				system("cls");
				printLayout();
				break;
			}
			else if (row[playerPos1][playerPos2 + 1] == 'X')
			{
				cout << "Congratulations!" << endl;
				cout << "Game over! " << endl;
				gameover = 1;
				break;
			}
			else if (row[playerPos1][playerPos2 + 1] == 'T')
			{
				
				cout << "Game over! " << endl;
				gameover = 1;
				break;
			}
			else
			{
				row[playerPos1][playerPos2 + 1] = row[playerPos1][playerPos2];
				row[playerPos1][playerPos2] = '.';
				playerPos1 = playerPos1;
				playerPos2 = playerPos2 + 1;
				system("cls");
				printLayout();
				break;
			}
		default:
			cout << "Please use wasd! \n" << endl;
			system("cls");
			printLayout();
		}
	}
	//return playerPos1, playerPos2;
}


void game()
{
	layout();
	getPos();
}