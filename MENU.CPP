#include<iostream.h>
#include<conio.h>
#include<string.h>

class BUTTON
{
 char Text[10];
 int X,Y;
 int L,B;
public:
 void set(int x,int y, int l, int b, char text[])
 {
  X=x;
  Y=y;
  L=l;
  B=b;
  strcpy(Text,text);
 }
 void Display();
};

class MENU
{
 int numButtons;
 BUTTON buttons[10];
 char Title[20];
 int X,Y;
 int L_b, B_b;
 char buttonText[][10];
 void SetButtons();
public:
 MENU(char T[],int N,int x, int y, int L, int B, char button_text[][10]);
 void Display();
};

MENU::MENU(char T[],int N,int x, int y, int L, int B, char button_text[][10])
{
 strcpy(Title,T);
 numButtons=N;
 L_b=L;
 B_b=B;
 X=x;
 Y=y;
 for (int i = 0;i<numButtons;i++)
  strcpy(buttonText[i],button_text[i]);
 SetButtons();
}

void MENU::SetButtons()
{
 for (int i = 0;i<numButtons+1;i++)
  buttons[i].set(X,Y+(i*B_b),L_b,B_b,buttonText[i]);
}

void BUTTON::Display()
{
 gotoxy(X,Y);
 cout<<char(218);
 for (int i = 0; i<L-2;i++)
  cout<<char(196);
 cout<<char(191);
 cout<<endl;
 for (i = 1;i<=B-2;i++)
 {
  gotoxy(X,Y+i);
  cout<<char(179);
  for (int j = 0;j<L-2;j++)
   cout<<' ';
  cout<<char(179);
  cout<<endl;
 }
 gotoxy(X,Y+i);
 cout<<char(192);
 for (i=0;i<L-2;i++)
  cout<<char(196);
 cout<<char(217);
 gotoxy(X+L/2-(strlen(Text)/2),Y+((B-1)/2));
 cout<<Text;
 cout<<endl;
}

void MENU::Display()
{
 cout<<Title;
 for (int i = 0; i<numButtons;i++)
  buttons[i].Display();
}

void main()
{
 clrscr();
 getch();
}