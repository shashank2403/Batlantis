#include<fstream.h>
#include<dos.h>
#include<graphics.h>
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
void AdminSearch();
void AdminEdit();
void AdminView();
void CustMain();
void CustBook();
void CustBookTickets();
void CustBookPackage();
void CustBookSeats(int,int,int,int);
void CustViewBooking();
void CustBrowse();
void CustSearch();
void CustTransaction(int,int,int,int);
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
 int R1,R2,H,S;
 public:
 void Write();
}

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
  putch(char(214));		//201
  for (int i = 0;i<L-2;i++)
   putch(char(196));	        //205
  putch(char(183));             //187
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

void printLogo()
{
 //..
}

int contains(int A[][2], int R,int C, int N)
{
 for (int i = 0;i<N;i++)
  if (A[i][0]==R && A[i][1] == C)
   return 1;
 return 0;
}

void printSeats(char seats[][20],int R,int C,int sel[][2],int Nsel, int cursel[2])
{
 for (int i = 0;i<R;i++)
 {
  for(int j = 0;j<C;j++)
  {
   if (contains(sel,i,j,Nsel)||(cursel[0]==i && cursel[1] ==j))
    textcolor(LIGHTBLUE);
   else if (seats[i][j]=='B')
    textcolor(RED);
   else if (seats[i][j]=='E')
    textcolor(LIGHTGREEN);
   putch(char(178));
   cout<<" ";
  }
  cout<<endl<<endl;
 }

}


/**********************************MENUS*************************************/

void MainMenu() 			//0
{
 char T[][20] = {"Administrator Login","Customer Login","View Credits","Quit"};
 MENU M("LOGO HERE",4,25,5,30,3,T);
 while(1)
 {
  clrscr();
  M.Display();
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

void AdminLogin()			//1
{
 clrscr();
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

void AdminMain()			//10
{
 char T[][20] = {"View bookings","Search booking","Edit attractions","Back"};
 MENU M("LOGO HERE",4,25,5,30,3,T);
 while(1)
 {
  clrscr();
  M.Display();
  char in=getch();
  if (in==UP && M.gsel()>1)
   M.psel(M.gsel()-1);
  else if (in==DOWN && M.gsel()<M.Rnum())
   M.psel(M.gsel()+1);
  else if (in==ENTER)
   if (M.gsel()==1)
    AdminView();
   else if (M.gsel()==2)
    AdminSearch();
   else if (M.gsel()==3)
    AdminEdit();
   else if (M.gsel()==4)
    break;
 }
}

void AdminEdit()
{
 clrscr();
 delay(1000);
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
 while(1)
 {
  clrscr();
  M.Display();
  char in=getch();
  if (in==ENTER)
   if (M.gsel()==1)
    break;
 }
}

void CustMain() 			//2
{
 char T[][20]={"Book tickets","Check booking","Browse attractions","Back"};
 MENU M("LOGO HERE",4,25,5,30,3,T);
 while(1)
 {
  clrscr();
  M.Display();
  char in=getch();
  if (in==UP && M.gsel()>1)
   M.psel(M.gsel()-1);
  else if (in==DOWN && M.gsel()<M.Rnum())
   M.psel(M.gsel()+1);
  else if (in==ENTER)
   if (M.gsel()==1)
    CustBook();
   else if (M.gsel()==2)
    CustSearch();
   else if (M.gsel()==3)
    CustBrowse();
   else if (M.gsel()==4)
    break;
 }
}

void CustBrowse()			//23
{
 cout<<"View attractions here";
 char T[][20] = {"Back"};
 MENU M("",1,30,20,20,3,T);
 while(1)
 {
  clrscr();
  M.Display();
  char in=getch();
  if (in==ENTER)
   if (M.gsel()==1)
    break;
 }
}

void CustBook()                         //21
{
 char T[][20]={"Book Package","Book Tickets","Back"};
 MENU M("LOGO HERE",3,25,5,30,3,T);
 M.Display();
 while(1)
 {
  clrscr();
  M.Display();
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
 MENU M("LOGO HERE",4,25,5,30,3,T);
 M.Display();
 while(1)
 {
  clrscr();
  M.Display();
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
 MENU M("LOGO HERE",5,25,5,30,3,T);
 clrscr();
 int R1,R2,H,S;
 M.Display();
 _setcursortype(_NORMALCURSOR);
 gotoxy(43,6);
 cin>>R1;
 M.psel(M.gsel()+1);
 clrscr();
 M.Display();
 gotoxy(43,6);
 cout<<R1;
 gotoxy(43,9);
 cin>>R2;
 M.psel(M.gsel()+1);
 clrscr();
 M.Display();
 gotoxy(43,6);
 cout<<R1;
 gotoxy(43,9);
 cout<<R2;
 gotoxy(46,12);
 cin>>H;
 M.psel(M.gsel()+1);
 clrscr();
 M.Display();
 gotoxy(43,6);
 cout<<R1;
 gotoxy(43,9);
 cout<<R2;
 gotoxy(46,12);
 cout<<H;
 gotoxy(40,15);
 cin>>S;
 M.psel(M.gsel()+1);
 clrscr();
 M.Display();
 gotoxy(43,6);
 cout<<R1;
 gotoxy(43,9);
 cout<<R2;
 gotoxy(46,12);
 cout<<H;
 gotoxy(40,15);
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

void CustTransaction()
{
 cout<<"Transaction here";
 char T[][20] = {"Confirm Transaction","Cancel Transaction"};
 MENU M("",2,25,15,30,3,T);
 M.Display();

 //Downloaded>>2
}

void CustBookSeats(int R1,int R2,int H, int S)
{
 clrscr();
 fstream fil("bookings.dat",ios::in|ios::binary);
 BOOKING B;
 while(fil.read((char*)&B,sizeof(B)))
 {
  //...DO NOT RUN
 }

 int sel[5][2],Nsel=0, cursel[2]={0,0};
 /*temp --> comes from file*/char seats[][20] = {{'E','E','B','B','E'},{'E','B','B','B','E'},{'B','B','B','B','B'}};
 int R,C;
 R=7;
 C=20;
 /*tempval*/int classicLimit=1,premiumLimit=2,jokerLimit=3;
 int cost=0;
 int classicCost=5,premiumCost=10,jokerCost=20;
 while(Nsel<S)
 {
  clrscr();
  printSeats(seats,R,C,sel,Nsel,cursel);
  char in = getch();
  if (in==UP&&cursel[0]>0&&!contains(sel,cursel[0]-1,cursel[1],Nsel))
   cursel[0]--;
  else if (in==DOWN&&cursel[0]<R-1&&!contains(sel,cursel[0]+1,cursel[1],Nsel))
   cursel[0]++;
  else if (in==RIGHT&&cursel[1]<C-1&&!contains(sel,cursel[0],cursel[1]+1,Nsel))
   cursel[1]++;
  else if (in==LEFT&&cursel[1]>0&&!contains(sel,cursel[0],cursel[1]-1,Nsel))
   cursel[1]--;
  else if (in==ENTER)
  {
   if (!contains(sel,cursel[0],cursel[1],S))
   {
    sel[Nsel][0]=cursel[0];
    sel[Nsel++][1]=cursel[1];
    if (cursel[1]<R)
     cursel[1]++;
    else cursel[1]--;
   }
  }
 }
 for (int i = 0;i<S;i++)
  if (sel[i][0]<classicLimit)
   cost+=classicCost;
  else if (sel[i][0]<premiumLimit)
   cost+=premiumCost;
  else cost+=jokerCost;
 cout<<cost;
 getch();

}

void CustSearch()
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
 textcolor(WHITE);
 _setcursortype(_NOCURSOR);
 //WelcomeScreen();
 //MainMenu();
 CustBookSeats(3,3,3,3);
 getch();
}