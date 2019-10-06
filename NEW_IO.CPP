#include<fstream.h>
#include<dos.h>
#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

#define UP 72
#define DOWN 80
#define RIGHT 77
#define LEFT 75
#define ENTER 13

void MainMenu();
void AdminLogin();
void AdminMain();
void AdminEdit();
void AdminView();
void CustMain();
void CustBook();
void CustBookTickets();
void CustBookPackage();
void CustBookSeats(int,int,int,int);
void CustBrowse();
void SearchBooking();
void CustTransaction(int,int,int,int, int[][2],int);
void ViewCredits();

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
 void Display(int);
};

class MENU
{
 int numButtons;
 BUTTON buttons[10];
 char Title[20];
 int X,Y;
 int L_b, B_b;
 char buttonText[][20];
 int sel;
 void SetButtons();
public:
 MENU(char T[],int N,int x, int y, int L, int B, char button_text[][20]);
 void Display();
 int gsel(){return sel;}
 void psel(int k){sel=k;}
 int Rnum(){return numButtons;}
};

struct BOOKING
{
 int id;
 int R1,R2,H,S;
 int seats[10][2];
};

void ViewBooking(BOOKING B);
MENU::MENU(char T[],int N,int x, int y, int L, int B, char button_text[][20])
{
 strcpy(Title,T);
 numButtons=N;
 L_b=L;
 B_b=B;
 X=x;
 Y=y;
 for (int i = 0;i<numButtons;i++)
  strcpy(buttonText[i],button_text[i ]);
 SetButtons();
 sel=1;
}

void MENU::SetButtons()
{
 for (int i = 0;i<numButtons+1;i++)
  buttons[i].set(X,Y+(i*B_b),L_b,B_b,buttonText[i]);
}

void BUTTON::Display(int sel=0)
{
 gotoxy(X,Y);
 textcolor(BLUE);
 if (sel)
 {
  putch(char(214));
  for (int i = 0;i<L-2;i++)
   putch(char(196));
  putch(char(183));
  cout<<endl;
  for (i = 1;i<=B-2;i++)
  {
   gotoxy(X,Y+i);
   putch(char(186));
   for (int j = 0;j<L-2;j++)
    cout<<' ';
   putch(char(186));
   cout<<endl;
  }
  gotoxy(X,Y+(B-1));
  putch(char(211));
  for (i = 0; i<L-2;i++)
   putch(char(196));
  putch(char(189));
 }
 else
 {

  cout<<char(218);
  for (int i = 0;i<L-2;i++)
   cout<<char(196);
  cout<<char(191)<<endl;
  for (i = 1;i<=B-2;i++)
  {
   gotoxy(X,Y+i);
   cout<<char(179);
   for (int j = 0;j<L-2;j++)
    cout<<' ';
   cout<<char(179);
   cout<<endl;

  }
  gotoxy(X,Y+(B-1));
  cout<<char(192);
  for (i = 0; i<L-2;i++)
   cout<<char(196);
  cout<<char(217);
 }
 textcolor(WHITE);
 if (sel)
  textcolor(LIGHTGREEN);
 gotoxy(X+(L/2)-(strlen(Text)/2),Y+(B/2));
 cprintf(Text);
 textcolor(WHITE);
 cout<<endl;
}

void MENU::Display()
{
 gotoxy(X+10,Y-3);
 cout<<Title;
 for (int i = 0; i<numButtons;i++)
   buttons[i].Display(sel==i+1);
}

/**********************************FUNCTIONS*********************************/
void WelcomeScreen()
{
 int gd = DETECT, gm,i;
 initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
 //---curve-1
 line(26,192,39,198);delay(70);line(39,198,49,203);delay(70);line(49,203,61,210);delay(70);
 line(61,210,73,218);delay(70);line(73,218,83,225);delay(70);line(83,225,91,233);delay(70);
 line(91,233,99,244);delay(70);line(99,244,106,256);delay(70);line(106,256,111,267);delay(70);
 line(111,267,113,276);delay(70);line(113,276,113,285);delay(70);line(113,285,112,294);delay(70);
 line(112,294,111,301);delay(70);line(111,301,110,308);delay(70);
  //--------------curve 2--
 line(110,308,122,308);delay(70);line(122,308,144,307);delay(70);line(144,307,165,307);delay(70);
 line(165,307,184,308);delay(70);line(184,308,200,310);delay(70);line(200,310,218,312);delay(70);
 line(218,312,232,316);delay(70);line(232,316,246,321);delay(70);line(246,321,256,327);delay(70);
 line(256,327,269,332);delay(70);line(269,332,279,339);delay(70);line(279,339,289,347);delay(70);
 line(289,347,298,356);delay(70);line(298,356,305,366);delay(70);line(305,366,310,374);delay(70);
 line(310,374,314,384);delay(70);line(314,384,320,397);delay(70);
 //-------------curve-4------
 line(613,192,604,196);delay(70);line(604,196,592,202);delay(70);line(592,202,579,208);delay(70);
 line(579,208,569,215);delay(70);line(569,215,559,223);delay(70);line(559,223,550,230);delay(70);
 line(550,230,542,240);delay(70);line(542,240,537,248);delay(70);line(537,248,531,258);delay(70);
 line(531,258,529,268);delay(70);line(529,268,526,279);delay(70);line(526,279,526,286);delay(70);
 line(526,286,526,297);delay(70);line(526,297,529,308);delay(70);
 //-------------curve-3------
 line(529,308,517,308);delay(70);line(517,308,497,307);delay(70);line(497,307,478,308);delay(70);
 line(478,308,459,309);delay(70);line(459,309,443,310);delay(70);
 line(443,310,427,312);delay(70);line(427,312,417,314);delay(70);line(417,314,400,319);delay(70);
 line(400,319,389,323);delay(70);line(389,323,378,328);delay(70);line(378,328,368,333);delay(70);
 line(368,333,360,339);delay(70);line(360,339,351,346);delay(70);line(351,346,343,353);delay(70);
 line(343,353,334,367);delay(70);line(334,367,326,379);delay(70);line(326,379,320,397);delay(70);
 //------------line 1
 line(26,192,220,192);delay(70);
 //-------curve 6
 line(220,192,222,200);delay(70);line(222,200,225,209);delay(70);line(225,209,229,216);delay(70);
 line(229,216,233,223);delay(70);line(233,223,240,228);delay(70);line(240,228,252,234);delay(70);
 line(252,234,269,237);delay(70);line(269,237,293,239);delay(70);line(293,239,297,235);delay(70);
 //------------line 7
 line(613,192,419,192);delay(70);
 //----------curve 5
 line(419,192,417,200);delay(70);line(417,200,415,208);delay(70);line(415,208,410,216);delay(70);
 line(410,216,404,224);delay(70);line(404,224,397,230);delay(70);line(397,230,386,234);delay(70);
 line(386,234,369,237);delay(70);line(369,237,346,239);delay(70);line(346,239,343,235);delay(70);
 //-line2
 line(297,235,301,200);delay(70);
 //--------line 3
 line(301,200,307,221);delay(70);
 //--------line3.1
 line(307,221,317,220);delay(70);
 //-----------line 4
 line(317,220,321,220);delay(70);
 //---------line 4.1
 line(321,220,331,221);delay(70);
 //------------line 5
 line(331,221,338,200);delay(70);
 ///----------line 6
 line(338,200,342,235);delay(70);
 //------------for fill color
 for(i=0;i<140;i++){
  setcolor(15);
  //---curve-1
  line(26+i,192,39+i,198);delay(1);line(39+i,198,49+i,203);delay(1);line(49+i,203,61+i,210);delay(1);
  line(61+i,210,73+i,218);delay(1);line(73+i,218,83+i,225);delay(1);line(83+i,225,91+i,233);delay(1);
  line(91+i,233,99+i,244);delay(1);line(99+i,244,106+i,256);delay(1);line(106+i,256,111+i,267);delay(1);
  line(111+i,267,113+i,276);delay(1);line(113+i,276,113+i,285);delay(1);line(113+i,285,112+i,294);delay(1);
  line(112+i,294,111+i,301);delay(1);line(111+i,301,110+i,308);delay(1);
  //-------------curve-4------
  line(613-i,192,604-i,196);delay(1);line(604-i,196,592-i,202);delay(1);line(592-i,202,579-i,208);delay(1);
  line(579-i,208,569-i,215);delay(1);line(569-i,215,559-i,223);delay(1);line(559-i,223,550-i,230);delay(1);
  line(550-i,230,542-i,240);delay(1);line(542-i,240,537-i,248);delay(1);line(537-i,248,531-i,258);delay(1);
  line(531-i,258,529-i,268);delay(1);line(529-i,268,526-i,279);delay(1);line(526-i,279,526-i,286);delay(1);
  line(526-i,286,526-i,297);delay(1);line(526-i,297,529-i,308);delay(1);
 }
 for(i=0;i<75;i++){
  setcolor(15);
  line(140,192+i,220,192+i);delay(1);
  line(419,192+i,500,192+i);delay(1);
 }
 for(i=0;i<80;i++){
 //-------curve 6
  setcolor(15);
    line(220,192+i,222,200+i);delay(1);line(222,200+i,225,209+i);delay(1);line(225,209+i,229,216+i);delay(1);
    line(229,216+i,233,223+i);delay(1);line(233,223+i,240,228+i);delay(1);line(240,228+i,252,234+i);delay(1);
    line(252,234+i,269,237+i);delay(1);line(269,237+i,293,239+i);delay(1);line(293,239+i,297,235+i);delay(1);

    //----------curve 5
    line(419,192+i,417,200+i);delay(1);line(417,200+i,415,208+i);delay(1);line(415,208+i,410,216+i);delay(1);
    line(410,216+i,404,224+i);delay(1);line(404,224+i,397,230+i);delay(1);line(397,230+i,386,234+i);delay(1);
    line(386,234+i,369,237+i);delay(1);line(369,237+i,346,239+i);delay(1);line(346,239+i,343,235+i);delay(1);
   //-line2
   line(297,235+i,301,200+i);delay(1);
   //--------line 3
   line(301,200+i,307,221+i);delay(1);
   //-----------line 4
    line(307,221+i,331,221+i);delay(1);
    //=-----------line 5
   line(331,221+i,338,200+i);delay(1);
   ///----------line 6
   line(338,200+i,342,235+i);delay(1);
			  }
       for(i=0;i<89;i++){            setcolor(15);
		line(307,221+i,331,221+i);delay(1);
      ////--------------curve 2--
      line(122,308-i,144,307-i);delay(1);line(144,307-i,165,307-i);delay(1);
    line(165,307-i,184,308-i);delay(1);line(184,308-i,200,310-i);delay(1);line(200,310-i,218,312-i);delay(1);
    line(218,312-i,232,316-i);delay(1);
    line(232,316-i,246,321-i);delay(1);line(246,321-i,256,327-i);delay(1);
    line(256,327-i,269,332-i);delay(1);line(269,332-i,279,339-i);delay(1);line(279,339-i,289,347-i);delay(1);
    line(289,347-i,298,356-i);delay(1);line(298,356-i,305,366-i);delay(1);line(305,366-i,310,374-i);delay(1);
    line(310,374-i,314,384-i);delay(1);line(314,384-i,320,397-i);delay(1);
       //-------------curve-3------

       line(517,308-i,497,307-i);delay(1);line(497,307-i,478,308-i);delay(1);
   line(478,308-i,459,309-i);delay(1);line(459,309-i,443,310-i);delay(1);
   line(443,310-i,427,312-i);delay(1);line(427,312-i,417,314-i);delay(1);
   line(417,314-i,400,319-i);delay(1);
   line(400,319-i,389,323-i);delay(1);line(389,323-i,378,328-i);delay(1);line(378,328-i,368,333-i);delay(1);
   line(368,333-i,360,339-i);delay(1);line(360,339-i,351,346-i);delay(1);line(351,346-i,343,353-i);delay(1);
   line(343,353-i,334,367-i);delay(1);line(334,367-i,326,379-i);delay(1);line(326,379-i,320,397-i);delay(1);
 }
 settextstyle(8,0,5);
 outtextxy(45,410,"WELCOME TO BAT CITY!");
 getch();
 closegraph();
}

int contains(int A[][2], int R,int C, int N)
{
 for (int i = 0;i<N;i++)
  if (A[i][0]==R && A[i][1] == C)
   return 1;
 return 0;
}

void printSeats(int X, int Y,int R,int C,int bookedSeats[][2], int Nbook,int sel[][2],int Nsel, int cursel[2])
{
 for (int i = 0;i<R;i++)
 {
  gotoxy(X,Y+(2*i));
  for(int j = 0;j<C;j++)
  {
   if (cursel[0]==i && cursel[1]==j)
    textcolor(5);
   else if (contains(sel,i,j,Nsel))
    textcolor(LIGHTBLUE);
   else if (contains(bookedSeats,i,j,Nbook))
    textcolor(RED);
   else textcolor(LIGHTGREEN);
   putch(char(178));
   cout<<" ";
  }
  cout<<endl<<endl;
  textcolor(WHITE);
 }
 for (i = 0;i<16;i++)
  putch(char(196));
 cout<<"STAGE HERE";
 for (i=0;i<17;i++)
  putch(char(196));
}

void deleteS(int A[][2], int &N, int R[2])
{
 for (int i  =0;i<N;i++)
 {
  if (A[i][0]==R[0] && A[i][1]==R[1])
  {
   for(int j =i;j<N-1;j++)
   {
    A[j][0] = A[j+1][0];
    A[j][1] = A[j+1][1];
   }
   break;
  }
 }
 N--;
}

void printLogo()
{
 //Line 1
 gotoxy(24,1);
 cout<<char(203)<<char(205)<<char(187)<<"      "<<char(186)<<"  "<<char(186);
 cout<<"          "<<char(186);\
 cout<<endl;
 //Line 2
 gotoxy(24,2);
 cout<<char(204)<<char(205)<<char(185)<<' '<<char(205)<<char(205)<<char(187)<<' '<<char(205)<<char(206)<<char(205)<<' '<<char(186)<<' '<<char(205)<<char(205)<<char(187);
 cout<<' '<<char(204)<<char(205)<<char(187)<<' '<<char(205)<<char(206)<<char(205)<<' '<<char(223);
 cout<<' '<<char(201)<<char(205)<<char(205);
 cout<<endl;
 //Line 3
 gotoxy(24,3);
 cout<<char(186)<<' '<<char(186)<<' '<<char(201)<<char(205)<<char(185)<<"  "<<char(186)<<"  "<<char(186)<<' '<<char(201)<<char(205)<<char(185);
 cout<<' '<<char(186)<<' '<<char(186)<<"  "<<char(186)<<"  "<<char(186);
 cout<<' '<<char(200)<<char(205)<<char(187);
 cout<<endl;
 //Line 4
 gotoxy(24,4);
 cout<<char(202)<<char(205)<<char(188)<<' '<<char(200)<<char(205)<<char(202)<<"  "<<char(186)<<"  "<<char(186)<<' '<<char(200)<<char(205)<<char(202);
 cout<<' '<<char(186)<<' '<<char(186)<<"  "<<char(186)<<"  "<<char(186);
 cout<<' '<<char(205)<<char(205)<<char(188);
}


/**********************************MENUS*************************************/

void MainMenu() 			//0
{
 char T[][20] = {"Administrator Login","Customer Login","View Credits","Quit"};
 MENU M("",4,25,8,30,3,T);
 while(1)
 {
  clrscr();
  M.Display();
  printLogo();
  char in=getch();
  if (in==UP && M.gsel()>1)
   M.psel(M.gsel()-1);
  else if (in==DOWN && M.gsel()<M.Rnum())
   M.psel(M.gsel()+1);
  else if (in==ENTER)
   if (M.gsel()==1)
    AdminLogin();
   else if (M.gsel()==2)
    CustMain();
   else if (M.gsel()==3)
    ViewCredits();
   else if (M.gsel()==4)
    exit(1);
 }
}

void AdminLogin()
{
 clrscr();
 printLogo();
 char U[10];
 gotoxy(30,10);
 cout<<"LOGIN DETAILS";
 gotoxy(25,12);
 cout<<"Username: ";
 gotoxy(25,13);
 cout<<"Password: ";
 _setcursortype(_NORMALCURSOR);
 gotoxy(35,12);
 cin>>U;
 gotoxy(35,13);
 char P[10];
 cin>>P;
 if (strcmp(U,"SHASHANK")==0 && strcmp(P,"PASSWORD")==0)
 {
  _setcursortype(_NOCURSOR);
  AdminMain();
 }
 else
 {
  gotoxy(20,20);
  cout<<"Incorrect password!";
  delay(1000);
  AdminLogin();
 }
}

void AdminMain()
{
 char T[][20] = {"View bookings","Search booking","Back"};
 MENU M("",3,25,8,30,3,T);
 while(1)
 {
  clrscr();
  M.Display();
  printLogo();
  char in=getch();
  if (in==UP && M.gsel()>1)
   M.psel(M.gsel()-1);
  else if (in==DOWN && M.gsel()<M.Rnum())
   M.psel(M.gsel()+1);
  else if (in==ENTER)
   if (M.gsel()==1)
    AdminView();
   else if (M.gsel()==2)
    SearchBooking();
   else if (M.gsel()==3)
    break;
 }
}

void AdminView()
{
 char T[][20] = {"Back"};
 MENU M("",1,30,23,20,3,T);
 int booked[20][2], Nbook=0;
 int R1=0,R2=0,H=0,S=0;
 fstream F("DATA.dat",ios::in|ios::binary);
 BOOKING B;
 while(F.read((char*)&B,sizeof(B)))
 {
  R1+=B.R1;
  R2+=B.R2;
  H+=B.H;
  S+=B.S;
  for (int i = 0;i<S;i++)
  {
   booked[Nbook][0] = B.seats[i][0];
   booked[Nbook++][1] = B.seats[i][1];
  }
 }
 F.close();
 int R=7,C=20;
 BUTTON P;
 P.set(12,6,20,3,"SEAT BOOKINGS");
 while(1)
 {
  clrscr();
  for (int i = 0; i<R;i++)
  {
   gotoxy(3,9+(2*i));
   for(int j  =0; j<C;j++)
   {
    if (contains(booked,i,j,Nbook))
     textcolor(RED);
    else textcolor(LIGHTGREEN);
    putch(char(178));
    cout<<' ';
   }
   textcolor(WHITE);
  }
  gotoxy(53,10);
  cout<<"Number of tickets booked ==>";
  gotoxy(55,12);
  cout<<"Ride 1: "<<R1;
  gotoxy(55,14);
  cout<<"Ride 2: "<<R2;
  gotoxy(55,16);
  cout<<"Haunted House: "<<H;
  gotoxy(55,18);
  cout<<"Show: " <<S;
  M.Display();
  P.Display();
  printLogo();
  char in=getch();
  if (in==ENTER)
   if (M.gsel()==1)
    break;
 }
}

void CustMain()
{
 char T[][20]={"Book tickets","Check booking","Browse attractions","Back"};
 MENU M("",4,25,8,30,3,T);
 while(1)
 {
  clrscr();
  M.Display();
  printLogo();
  char in=getch();
  if (in==UP && M.gsel()>1)
   M.psel(M.gsel()-1);
  else if (in==DOWN && M.gsel()<M.Rnum())
   M.psel(M.gsel()+1);
  else if (in==ENTER)
   if (M.gsel()==1)
    CustBook();
   else if (M.gsel()==2)
    SearchBooking();
   else if (M.gsel()==3)
    CustBrowse();
   else if (M.gsel()==4)
    break;
 }
}

void CustBrowse()
{
 cout<<"View attractions here";
 char T[][20] = {"Back"};
 MENU M("",1,30,20,20,3,T);
 while(1)
 {
  clrscr();
  M.Display();
  printLogo();
  char in=getch();
  if (in==ENTER)
   if (M.gsel()==1)
    break;
 }
}

void CustBook()                         //21
{
 char T[][20]={"Book Package","Book Tickets","Back"};
 MENU M("",3,25,8,30,3,T);
 M.Display();
 while(1)
 {
  clrscr();
  M.Display();
  printLogo();
  char in=getch();
  if (in==UP && M.gsel()>1)
   M.psel(M.gsel()-1);
  else if (in==DOWN && M.gsel()<M.Rnum())
   M.psel(M.gsel()+1);
  else if (in==ENTER)
  {
   if (M.gsel()==1)
    CustBookPackage();
   else if (M.gsel()==2)
    CustBookTickets();
   break;
  }
 }
}

void CustBookPackage()
{
 char T[][20] = {"Economy Package","Gold Package","Platinum Package","Back"};
 MENU M("",4,25,8,30,3,T);
 M.Display();
 while(1)
 {
  clrscr();
  M.Display();
  printLogo();
  char in=getch();
  if (in==UP && M.gsel()>1)
   M.psel(M.gsel()-1);
  else if (in==DOWN && M.gsel()<M.Rnum())
   M.psel(M.gsel()+1);
  else if (in==ENTER)
   if (M.gsel()==1)
   {
    CustBookSeats(1,1,1,1);
    break;
   }
   else if (M.gsel()==2)
   {
    CustBookSeats(2,2,6,4);
    break;
   }
   else if (M.gsel()==3)
   {
    CustBookSeats(4,4,8,10);
    break;
   }
   else if (M.gsel()==4)
    break;
 }
}

void CustBookTickets()
{
 cout<<"Book tickets here";
 char T[][20] = {"Ride 1:   ","Ride 2:   ","Haunted House:    ","Show:       ","Confirm"};
 MENU M("",5,25,8,30,3,T);
 clrscr();
 int R1,R2,H,S;
 M.Display();
 printLogo();
 _setcursortype(_NORMALCURSOR);
 gotoxy(43,9);
 cin>>R1;
 M.psel(M.gsel()+1);
 clrscr();
 M.Display();
 printLogo();
 gotoxy(43,9);
 cout<<R1;
 gotoxy(43,12);
 cin>>R2;
 M.psel(M.gsel()+1);
 clrscr();
 M.Display();
 printLogo();
 gotoxy(43,9);
 cout<<R1;
 gotoxy(43,12);
 cout<<R2;
 gotoxy(46,15);
 cin>>H;
 M.psel(M.gsel()+1);
 clrscr();
 M.Display();
 printLogo();
 gotoxy(43,9);
 cout<<R1;
 gotoxy(43,12);
 cout<<R2;
 gotoxy(46,15);
 cout<<H;
 gotoxy(40,18);
 cin>>S;
 M.psel(M.gsel()+1);
 clrscr();
 M.Display();
 printLogo();
 gotoxy(43,9);
 cout<<R1;
 gotoxy(43,12);
 cout<<R2;
 gotoxy(46,15);
 cout<<H;
 gotoxy(40,18);
 cout<<S;
 while(1)
 {
  char in=getch();
  if (in==ENTER)
   if (M.gsel()==5)
    break;
 }
 CustBookSeats(R1,R2,H,S);
}

void CustTransaction(int R1, int R2,int H, int S, int seats[10][2], int cost)
{
 clrscr();
 int id = random(10000)+1;
 char T[][20] = {"Confirm Transaction","Cancel Transaction"};
 MENU M("",2,25,20,30,3,T);
 while(1)
 {
  clrscr();
  gotoxy(20,8);
  cout<<"Booking Reference ID: "<<id;
  gotoxy(20,10);
  cout<<"Tickets for Ride 1: "<<R1;
  gotoxy(20,11);
  cout<<"Tickets for Ride 2: "<<R2;
  gotoxy(20,12);
  cout<<"Tickets for The Haunted House: "<<H;
  gotoxy(20,13);
  cout<<"Tickets for the show: "<<S;
  gotoxy(20,14);
  cout<<"Seats Booked: ";
  for (int i = 0;i<S;i++)
   cout<<char(seats[i][0]+65)<<seats[i][1]+1<<" ";
  gotoxy(20,16);
  cout<<"Total Cost: "<<cost;
  M.Display();
  printLogo();
  char in=getch();
  if (in==UP && M.gsel()>1)
   M.psel(M.gsel()-1);
  else if (in==DOWN && M.gsel()<M.Rnum())
   M.psel(M.gsel()+1);
  else if (in==ENTER)
   if (M.gsel()==1)
   {
    clrscr();
    BOOKING B;
    B.id=id;
    B.R1=R1;
    B.R2=R2;
    B.H=H;
    B.S=S;
    for (int i = 0; i<S;i++)
    {
     B.seats[i][0]=seats[i][0];
     B.seats[i][1]=seats[i][1];
    }
    fstream F("DATA.dat",ios::app|ios::binary);
    F.write((char*)&B,sizeof(B));           +
    F.close();
    ofstream R("RECEIPT.txt");
    R<<"      	   BATLANTIS\n";
    R<<"      Transaction Receipt\n";
    R<<"------------------------------------\n"<<endl;

    R<<"  Booking Reference ID ==> "<<id<<endl<<endl;
    R<<" Tickets booked for Ride 1: "<<R1<<endl;
    R<<" Tickets booked for Ride 2: "<<R2<<endl;
    R<<" Tickets booked for Haunted House: "<<H<<endl;
    R<<" Tickets booked for the Show: "<<S<<endl<<endl;
    R<<" Seats booked for the Show: ";
    for (i = 0;i<S;i++)
     R<<char(seats[i][0]+65)<<seats[i][1]+1<<" ";
    R<<endl<<endl;
    R<<"------------------------------------\n";
    R<<"       Total price==>"<<cost;
    R<<endl<<endl;
    R<<"Thanks for booking your entertainment with us!\n";
    R<<" We hope you have a great time at Batlantis!\n"<<endl<<endl;
    R<<"------------------------------------\n";
    R<< "Batright 2019. All rights reserved.";
    R.close();

    printLogo();
    gotoxy(30,10);
    cout<<"Downloaded receipt";
    delay(1000);
    break;
   }
   else if (M.gsel()==2)
    break;
 }
}

void CustBookSeats(int R1,int R2,int H, int S)
{
 clrscr();
 fstream fil("DATA.dat",ios::in|ios::binary);
 int booked[20][2], Nbook=0;
 BOOKING B;
 while(fil.read((char*)&B,sizeof(B)))
  for(int i = 0;i<B.S;i++)
  {
   booked[Nbook][0]=B.seats[i][0];
   booked[Nbook++][1]=B.seats[i][1];
  }
 fil.close();
 int sel[10][2],Nsel=0, cursel[2]={0,0};
 int R=7,C= 20;
 for (i = 0;i<R;i++)
  for (int j = 0;j<C;j++)
   if (!contains(booked,i,j,Nbook))
   {
    cursel[0]=i;
    cursel[1]=j;
    break;
   }
 int classicLimit=3,premiumLimit=6,jokerLimit=10;
 int cost=0;
 int classicCost=5,premiumCost=10,jokerCost=20;
 BUTTON T;
 T.set(10,6,21,3,"SELECT SEATS");
 while(Nsel<S)
 {
  clrscr();
  T.Display();
  printSeats(3,9,R,C,booked,Nbook,sel,Nsel,cursel);
  printLogo();
  char in = getch();
  if (in==UP&&cursel[0]>0&&!contains(booked,cursel[0]-1,cursel[1],Nbook))
   cursel[0]--;
  else if (in==DOWN&&cursel[0]<R-1&&!contains(booked,cursel[0]+1,cursel[1],Nbook))
   cursel[0]++;
  else if (in==RIGHT&&cursel[1]<C-1&&!contains(booked,cursel[0],cursel[1]+1,Nbook))
   cursel[1]++;
  else if (in==LEFT&&cursel[1]>0&&!contains(booked,cursel[0],cursel[1]-1,Nbook))
   cursel[1]--;
  else if (in==ENTER)
   if (!contains(sel,cursel[0],cursel[1],Nsel))
   {
    sel[Nsel][0]=cursel[0];
    sel[Nsel++][1]=cursel[1];
   }
   else
    deleteS(sel,Nsel,cursel);
  }

 for (i = 0;i<S;i++)
  if (sel[i][0]<classicLimit)
   cost+=classicCost;
  else if (sel[i][0]<premiumLimit)
   cost+=premiumCost;
  else cost+=jokerCost;
 char MT[][20] = {"Confirm Seats","Cancel booking"};
 MENU M("",2,45,10,20,3,MT);
 cursel[0] = -1;
 while(1)
 {
  clrscr();
  T.Display();
  printLogo();
  printSeats(3,9,R,C,booked,Nbook,sel,Nsel,cursel);
  M.Display();
  char in=getch();
  if (in==UP && M.gsel()>1)
   M.psel(M.gsel()-1);
  else if (in==DOWN && M.gsel()<M.Rnum())
   M.psel(M.gsel()+1);
  else if (in==ENTER)
   if (M.gsel()==1)
   {
    CustTransaction(R1,R2,H,S,sel,cost);
    break;
   }
   else if (M.gsel()==2)
    break;
 }
}

void SearchBooking()
{
 clrscr();
 _setcursortype(_NORMALCURSOR);
 int bookID;
 char T[][20] = {"Search booking","Search again","Back"};
 MENU M("",3,25,10,30,3,T);
 printLogo();
 gotoxy(20,7);
 cout<<"Enter Booking Reference ID: ";
 cin>>bookID;
 while(1)
 {
  clrscr();
  BOOKING B;
  M.Display();
  printLogo();
  char in=getch();
  if (in==UP && M.gsel()>1)
   M.psel(M.gsel()-1);
  else if (in==DOWN && M.gsel()<M.Rnum())
   M.psel(M.gsel()+1);
  else if (in==ENTER)
   if (M.gsel()==1)
   {
    int found=0;
    fstream F("DATA.dat",ios::in|ios::out);
    while(F.read((char*)&B,sizeof(B)) && !found)
     if (B.id==bookID)
      found=1;
    F.close();
    if (found)
    {
     ViewBooking(B);
     break;
    }
    else
    {
     gotoxy(27,8);
     cout<<"Sorry, Booking not found!";
     delay(1000);
     SearchBooking();
     break;
    }
   }
   else if (M.gsel()==2)
   {
    SearchBooking();
    break;
   }
   else if (M.gsel()==3)
    break;
 }
}

void ViewBooking(BOOKING B)
{
 char T[][20] = {"Cancel Booking","Back"};
 MENU M("",2,60,10,20,3,T);
 while(1)
 {
  clrscr();
  gotoxy(5,10);
  cout<<"Booking Refernce ID: "<<B.id;
  gotoxy(5,12);
  cout<<"Ride 1: "<<B.R1;
  gotoxy(5,13);
  cout<<"Ride 2: "<<B.R2;
  gotoxy(5,14);
  cout<<"Haunted House: "<<B.H;
  gotoxy(5,15);
  cout<<"Show: "<<B.S;
  gotoxy(5,16);
  cout<<"Seats: ";
  for (int i = 0;i<B.S;i++)
   cout<<char(B.seats[i][0]+65)<<B.seats[i][1]+1<<' ';
  M.Display();
  printLogo();
  char in=getch();
  if (in==UP && M.gsel()>1)
   M.psel(M.gsel()-1);
  else if (in==DOWN && M.gsel()<M.Rnum())
   M.psel(M.gsel()+1);
  else if (in==ENTER)
   if (M.gsel()==1)
   {
    BOOKING temp;
    fstream Fil1,Fil2;
    Fil1.open("DATA.dat",ios::binary|ios::in);
    Fil2.open("TEMP.dat",ios::binary|ios::out);
    while (Fil1.read((char*)&temp,sizeof(temp)))
    {
     if (B.id!=temp.id)
      Fil2.write((char*)&temp,sizeof(temp));
    }
    Fil1.close();
    Fil2.close();
    remove("DATA.dat");
    rename("TEMP.dat","DATA.dat");
    clrscr();
    printLogo();
    gotoxy(20,10);
    cout<<"Booking cancelled!";
    delay(2000);
    break;
   }
   else if (M.gsel()==2)
    break;
 }
}

void ViewCredits()
{
 clrscr();
 char T[][20] = {"Back"};
 MENU M("",1,30,20,30,3,T);
 while(1)
 {
  clrscr();
  cout<<"View credits here";
  M.Display();
  printLogo();
  char in=getch();
  if (in==ENTER)
   if (M.gsel()==1)
    break;
 }
}
/**********************************MAIN**************************************/

void main()
{
 clrscr();
 randomize();
 textcolor(WHITE);
 _setcursortype(_NOCURSOR);
 //WelcomeScreen();
 MainMenu();
 getch();
}