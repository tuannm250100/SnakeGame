#include<iostream>
#include<string>
#include<conio.h> 
#include<windows.h>
using namespace std;

const int width = 30;
const int hight = 15;
int foodx, foody;
int x;
int y;
int score = 0;
int tailx[200] = {0};
int taily[200] = {0};
int tail = 0;
enum direction{ LEFT, RIGHT, UP, DOWN };
direction dir;
bool gameover;


void start()
{
  gameover = false;
  x = width / 2;
  y = hight / 2;
  foodx = rand() % width;
  foody = rand() % hight;
}


void frame()
{
  system("cls");

  for (int i = 0; i < width + 2; i++)
  cout << "#";
  cout << endl;
  
  for (int i = 0; i < hight; i++)
  {
    for (int j = 0; j < width; j++)
    {
      if (j == 0)
      {
        cout << "#";
      }
     
     if (i == y&&j == x)
     cout << "O";

     else if (i == foody&&j == foodx)
     cout << "*";

    else
    {
    bool print = false;

    for (int k = 0; k < tail; k++)
    {
      if (tailx[k] == j&&taily[k] == i)
      {
        cout << "0";
        print = true;
     }
    }

     if (!print)  
     {
      cout << " ";
     }
   }

    if (j == width - 1)
    {
      cout << "#";
    }
 }

 cout << endl;
}

for (int i = 0; i < width + 2; i++)
{
  cout << "#";

}
 //cout << endl;
 //cout << "SCORE: " << score << endl;
}


void direct()
{
  if (_kbhit())
  {
   switch (_getch())
   {
    case'a':
    dir = LEFT;
    break;
    case 75: 
	dir = LEFT;
    break;
    case's':
    dir = DOWN;
    break;
    case 80: 
	dir = DOWN;
    break;
    case'w':
    dir = UP;
    break;
    case 72: 
	dir = UP;
    break;
    case'd':
    dir = RIGHT;
    break;
    case 77: 
	dir = RIGHT;
    break;
   }
  }
}


void move()
{
  int previousx = tailx[0];
  int previousy = taily[0];
  int prev2x = 0;
  int prev2y = 0;
  tailx[0] = x;
  taily[0] = y;
 for (int i = 1; i < tail; i++)
 {
  prev2x = tailx[i];
  prev2y = taily[i];
  tailx[i] = previousx;
  taily[i] = previousy;
  previousx = prev2x;
  previousy = prev2y;

 }

 switch (dir)
 {
  case LEFT:
  x--;
  break;
  case RIGHT:
  x++;
  break;
  case UP:
  y--;
  break;
  case DOWN:
  y++;
  break;
  default:
  break;
 }

 if (x>width - 1 || x<0 || y > hight - 1 || y<0)
 gameover = true;

 for (int i = 0; i < tail; i++)
 {
   if (tailx[i] == x&&taily[i] == y)
      gameover = true;
 }

 if (x == foodx&&y == foody)
 {
  foodx = rand() % width;
  foody = rand() % hight;
  tail++; 
  score += 10;
 }

}

void hidecursor()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle,&info);
}

int main()
{ 
hidecursor();
  string a;
  cout << "\n\n\n\t\t\t\t THE SNAKE GAME\n\n";
  cout << "CONTROLS:\n\nW, up arrow=UP\nS, down arrow=DOWN\nA, right arrow=RIGHT\nD, left arrow=LEFT\n\n\n";
  cout << "PLEASE ENTER YOUR NAME: ";
  cin >> a;

  start();

 while (!gameover)//game condition is true
 {

  frame();
  direct();
  move();
  Sleep(70);
 }
 system("cls");

  cout << "\n\n\nOPPS YOU ARE OUT" << "\tTRY AGAIN";
  cout << endl;
  cout << a << " YOUR SCORE IS: " << score << endl;
}