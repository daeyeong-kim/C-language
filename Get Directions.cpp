#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>


#define COL GetStdHandle(STD_OUTPUT_HANDLE)
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define MAX 1024
#define RED SetConsoleTextAttribute(COL,0x000c);
#define GOLD SetConsoleTextAttribute(COL,0x0006);
#define BLUE SetConsoleTextAttribute(COL,0x0001);
#define WHITE SetConsoleTextAttribute(COL,0x0007);

typedef struct REPLAY
{
 int unitx;
 int unity;
 int sasa1x;
 int sasa1y;
 int sasa2x;
 int sasa2y;

}REPLAY;

void init();
void mazeDrow();
void unitMove(char);
void gotoxy(int x, int y);
void returnGame();
void random(int);
void random12(int);
int gameOver(char, int, REPLAY k[MAX]);
void returnGame();
void replayGame(int, REPLAY k[MAX]);







int maze[19][19] =
{ { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
{ 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
{ 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1 },
{ 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1 },
{ 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1 },
{ 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1 },
{ 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1 },
{ 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1 },
{ 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1 },
{ 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1 },
{ 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1 },
{ 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1 },
{ 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1 },
{ 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1 },
{ 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1 },
{ 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
{ 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1 },
{ 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 } };   //맵;
int nowX = 17; int nowY = 7;
int randomX = 2; int randomY = 17;
int random1 = 5; int random2 = 5;


int main()
{
 int input;
 FILE *fp;
 FILE *fpp;

 

 int x, suffle = 0;
 srand((unsigned)time(NULL));  //난수 발생
 init();
 //mazeDrow();
 char a = 1;
 
 gotoxy(5, 10);
 printf("지난 게임을 불러오시겠습니까?(불러오기:\"1\" 새게임:\"아무거나 누르세요\")");
 scanf("%d", &input);
 

 while (a != 'q')
 {
  if (input == 1)
  {
   fpp = fopen("test.txt", "r");
   if (fpp == NULL)
   {
    printf("불러오기 실패 종료합니다.  새게임을 하세요~");
    return 0;
   }
   maze[nowX][nowY] = 0;
   maze[randomX][randomY] = 0;
   maze[random1][random2] = 0;
   fscanf(fpp, "%d %d %d %d %d %d", &nowX, &nowY, &randomX,&randomY,&random1,&random2);
   maze[nowX][nowY] = 3;
   maze[randomX][randomY] = 5;
   maze[random1][random2] = 5;

   fclose(fpp);
  }
  REPLAY test[MAX];
  x = rand() % 4 + 1;
  a = getch();
  system("cls");
  unitMove(a);     //유닛 이동
  random(x);  //지뢰 1 이동
  random12(x); //지뢰 2이동
  fp = fopen("test.txt", "wt");
  test[suffle].unitx = nowX;
  test[suffle].unity = nowY;
  test[suffle].sasa1x = randomX;
  test[suffle].sasa1y = randomY;
  test[suffle].sasa2x = random1;
  test[suffle].sasa2y = random2;    //정보입력

  fprintf(fp, "%d  %d  %d  %d  %d  %d",nowX,nowY,randomX,randomY,random1,random2);

  mazeDrow();      //이동 지뢰,유닛 움직이기
  suffle++;
  gameOver(a, suffle, test);   //게임오버
 }
 fclose(fp);
}


void init()
{
 maze[1][0] = 2;
 maze[17][7] = 3;
 maze[2][17] = 5;
 maze[5][5] = 5;
}

void mazeDrow()    //유닛 그리기
{
 for (int i = 0; i < 19; i++)
 {
  for (int k = 0; k < 19; k++)
  {
   switch (maze[i][k])
   {
   case 5:
    RED printf("死");
    break;
   case 3:
    GOLD printf("●");
    break;
   case 2:
    printf("  ");
    break;
   case 1:
    WHITE printf("■");
    break;
   case 0:
    printf("  ");
    break;
   }

  }
  printf("\n");
 }
}


void unitMove(char a)
{
 if (a == UP)
 {
  if (maze[nowX - 1][nowY] == 1)
   return;
  maze[nowX - 1][nowY] = 3;
  maze[nowX][nowY] = 0;
  nowX--;
 }
 else if (a == RIGHT)
 {
  if (maze[nowX][nowY + 1] == 1)
   return;
  maze[nowX][nowY + 1] = 3;
  maze[nowX][nowY] = 0;
  nowY++;
 }
 else if (a == LEFT)
 {
  if (maze[nowX][nowY - 1] == 1)
   return;
  maze[nowX][nowY - 1] = 3;
  maze[nowX][nowY] = 0;
  nowY--;
 }
 else if (a == DOWN)
 {
  if (maze[nowX + 1][nowY] == 1)
   return;
  maze[nowX + 1][nowY] = 3;
  maze[nowX][nowY] = 0;
  nowX++;
 }
}


void gotoxy(int x, int y)
{
 COORD Pos = { x - 1, y - 1 };
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void returnGame()
{
 init();
 nowX = 17;
 nowY = 7;
 randomX = 2;
 randomY = 17;
 random1 = 5;
 random2 = 5;

}


void random(int x)
{
 if (x == 1)
 {
  if (maze[randomX - 1][randomY] == 1)
   return;
  maze[randomX - 1][randomY] = 5;
  maze[randomX][randomY] = 0;
  randomX--;
 }
 else if (x == 2)
 {
  if (maze[randomX][randomY + 1] == 1)
   return;
  maze[randomX][randomY + 1] = 5;
  maze[randomX][randomY] = 0;
  randomY++;
 }
 else if (x == 3)
 {
  if (maze[randomX][randomY - 1] == 1)
   return;
  maze[randomX][randomY - 1] = 5;
  maze[randomX][randomY] = 0;
  randomY--;
 }
 else if (x == 4)
 {
  if (maze[randomX + 1][randomY] == 1)
   return;
  maze[randomX + 1][randomY] = 5;
  maze[randomX][randomY] = 0;
  randomX++;
 }
}


void random12(int x)
{
 if (x == 1)
 {
  if (maze[random1 - 1][random2] == 1)
   return;
  maze[random1 - 1][random2] = 5;
  maze[random1][random2] = 0;
  random1--;
 }
 else if (x == 2)
 {
  if (maze[random1][random2 + 1] == 1)
   return;
  maze[random1][random2 + 1] = 5;
  maze[random1][random2] = 0;
  random2++;
 }
 else if (x == 3)
 {
  if (maze[random1][random2 - 1] == 1)
   return;
  maze[random1][random2 - 1] = 5;
  maze[random1][random2] = 0;
  random2--;
 }
 else if (x == 4)
 {
  if (maze[random1 + 1][random2] == 1)
   return;
  maze[random1 + 1][random2] = 5;
  maze[random1][random2] = 0;
  random1++;
 }
}

int gameOver(char a, int suffle, REPLAY k[MAX])
{

 if (maze[nowX][nowY] == maze[randomX][randomY])
 {
  system("cls");
  maze[nowX][nowY] = 0;
  maze[randomX][randomY] = 0;
  maze[random1][random2] = 0;
  gotoxy(20, 40);


  do
  {
   puts("GAME OVER 다시할려면 1을누르세요.(종료 :q,리플레이 :r)");
   a = getch();

   if (a == 'q')
   {

    exit(123);
   }
   else if (a == 'r')
   {

    replayGame(suffle, k);
   }
   else if (a != '1')
   {
    printf("잘못입력하였습니다.");

   }

  } while (a != '1');

  returnGame();
 }
 else if (maze[nowX][nowY] == maze[random1][random2])
 {
  system("cls");
  maze[nowX][nowY] = 0;
  maze[randomX][randomY] = 0;
  maze[random1][random2] = 0;
  gotoxy(20, 20);

  do
  {
   puts("GAME OVER 다시할려면 1을누르세요.(종료 :q,리플레이 :r)");

   a = getch();

   if (a == 'q')
   {

    exit(123);
   }
   else if (a == 'r')
   {

    replayGame(suffle, k);
   }
   else if (a != '1')
   {
    printf("잘못입력하였습니다.");

   }

  } while (a != '1');

  returnGame();
 }
 else if (maze[1][0] == 3)
 {
  system("cls");
  gotoxy(20, 20);


  do
  {
   puts("GAME OVER 다시할려면 1을누르세요.(종료 :q,리플레이 :r)");

   a = getch();

   if (a == 'q')
   {

    exit(123);
   }
   else if (a == 'r')
   {

    replayGame(suffle, k);
   }
   else if (a != '1')
   {
    printf("잘못입력하였습니다.");

   }

  } while (a != '1');

  returnGame();
 }

 return a;
}

void replayGame(int x, REPLAY k[MAX])
{
 maze[nowX][nowY] = 0;
 maze[randomX][randomY] = 0;
 maze[random1][random2] = 0;
 system("cls");

 for (int i = 1; i < x; i++)
 {

  maze[k[i].unitx][k[i].unity] = 3;
  maze[k[i - 1].unitx][k[i - 1].unity] = 0;
  maze[k[i].sasa1x][k[i].sasa1y] = 5;
  maze[k[i - 1].sasa1x][k[i - 1].sasa1y] = 0;
  maze[k[i].sasa2x][k[i].sasa2y] = 5;
  maze[k[i - 1].sasa2x][k[i - 1].sasa2y] = 0;
  mazeDrow();
  Sleep(100);
  system("cls");     //그리기
 }
 returnGame();


}
