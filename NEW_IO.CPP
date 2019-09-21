#include<iostream.h>
#include<dos.h>
#include<conio.h>
#include<string.h>

#define UP 80
#define DOWN 72
#define RIGHT 77
#define LEFT 75

/**********************************CLASSES***********************************/
class BUTTON
{
 char Text[20];
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
 char buttonText[][20];
 void SetButtons();
public:
 MENU(char T[],int N,int x, int y, int L, int B, char button_text[][20]);
 void Display();
};

MENU::MENU(char T[],int N,int x, int y, int L, int B, char button_text[][20])
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
 cprintf(Text);
 cout<<endl;
}

void MENU::Display()
{
 gotoxy(X+10,Y-3);
 cout<<Title;
 for (int i = 0; i<numButtons;i++)
   buttons[i].Display();
}

void printLogo()
{
 //...
}

/**********************************MENUS*************************************/

void MainMenu() 			//0
{
 char T[][20] = {"Administrator Login","Customer Login","View Credits","Quit"};
 MENU M("LOGO HERE",4,25,5,30,3,T);
 M.Display();
}

void AdminLogin()			//1
{
 char U[10],P[10];
 gotoxy(30,10);
 cout<<"LOGIN DETAILS";
 gotoxy(25,12);
 cout<<"Username: ";
 gotoxy(25,13);
 cout<<"Password: ";
 gotoxy(35,12);
 cin>>U;
 gotoxy(35,13);
 cin>>P;
}

void AdminMain()			//10
{
 char T[][20] = {"View bookings","Search booking","Download details","Back"};
 MENU M("LOGO HERE",4,25,5,30,3,T);
 M.Display();
}

void AdminDownload()			//103
{
 gotoxy(34,13);
 cout<<"DOWNLOADED";
 //delay>>10
}

void AdminSearch()			//102
{
 cout<<"Search for entry";
}

void AdminView()                        //101
{
 cout<<"View file";
 char T[][20] = {"Back"};
 MENU M("",1,30,20,20,3,T);
 M.Display();
}

void CustMain() 			//2
{
 char T[][20]={"Book tickets","Check booking","Browse attractions","Back"};
 MENU M("LOGO HERE",4,25,5,30,3,T);
 M.Display();
}

void CustBrowse()			//23
{
 cout<<"View attractions here";
 char T[][20] = {"Back"};
 MENU M("",1,30,20,20,3,T);
 M.Display();
}

void CustBook()                         //21
{
 char T[][20]={"Book Package","Book Tickets","Back"};
 MENU M("LOGO HERE",3,25,5,30,3,T);
 M.Display();
}

void CustBookPackage() 			//211
{
 char T[][20] = {"Economy Package","Gold Package","Platinum Package","Back"};
 MENU M("LOGO HERE",4,25,5,30,3,T);
 M.Display();
}

void CustBookTickets() 			//212
{
 cout<<"Book tickets here";
}

void CustTransaction()                  //21100,21200
{
 cout<<"Transaction here";
 char T[][20] = {"Confirm Transaction","Cancel Transaction"};
 MENU M("",2,25,15,30,3,T);
 M.Display();

 //Downloaded>>2
}

void CustBookSeats() 		        //2110,2120
{
 cout<<"Book seats here";
}

void CustSearch()                       //22
{
 char bookID[10];
 gotoxy(30,15);
 cout<<"Enter your booking ID: ";
 cin>>bookID;
}

void CustViewBooking()
{
 cout<<"View details here";
 char T[][20] = {"Cancel Booking","Back"};
 MENU M("",2,60,10,20,3,T);
 M.Display();
}

/**********************************MAIN**************************************/
void main()
{
 clrscr();
 getch();
}