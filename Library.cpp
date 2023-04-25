
//********************** LIBRARY - MANAGEMENT ***********************
# include <iostream.h>
# include <fstream.h>
# include <process.h>
# include <string.h>
# include <stdio.h>
# include <conio.h>
# include <dos.h>

// FUNTION PROTOTYPE
void main_menu();
void book();
void member();
void issued();
void name();
void screen();
void music();
void quit();
// OBJECT DECLARATION
fstream inout,in;

// MAIN PROGRAM

void name()
{
gotoxy (52,18);
cout <<" PRESENTED BY :-";
gotoxy (52,19); cout <<" MAYANK";
}
class store
{
protected:
char bookname [20];
float bookprice;
char author[20];
public :
char status;
int bookcode;
void getdata();
void displaydata();
void b_disp();
void mod_data();
void deletion ();
}stor;
struct add
{
char hou_no[20];
char city [20];
};
class member1



{
char mem_name [20];
add address;
public :
int mem_id;
void get_data();
void display_data();
void modification();
void m_disp();
void dele();
}supp;

// DERIVED CLASS DECLARATION


class issued :public store , public member1
{
int issued_no;
int bookno;
int qty;
public:
void issue_detail();
}iss;
//**********************FUNCTION FOR RECIEVE
void member1::get_data()
{
textcolor(BLACK);
textbackground(WHITE);
gotoxy(22,1);cprintf("Y U G V E E N A   L I B R A R Y   S Y S T  E M");
gotoxy(15,2);cprintf("         MEMBER'S INFORMATION                 ");
gotoxy(2,5);cprintf("  CODE          MEM_NAME          HOUSE NO                          CITY");
textcolor(WHITE);
textbackground(BLACK);


int c=100;

inout.open("MEMBER.DAT ",ios::in|ios::binary);
inout.read((char*)&supp,sizeof(supp));
if (!inout)
{
supp.mem_id=100;
gotoxy(2,7);cout<<mem_id;
gotoxy(18,7);gets(mem_name);
gotoxy(37,7);gets(address.hou_no);
gotoxy(69,7);gets(address.city);
cout<<endl;
inout.close();


inout.open("MEMBER.DAT ",ios::out|ios::app|ios::binary);
inout.write((char*)&supp,sizeof(supp));
inout.close();

}
else
{
while (!inout.eof())
{
c=c+1;
inout.read((char*)&supp,sizeof(supp));
}
inout.close();
supp.mem_id=supp.mem_id+1;
gotoxy(2,7);cout<<mem_id;
gotoxy(18,7);gets(mem_name);
gotoxy(37,7);gets(address.hou_no);
gotoxy(69,7);gets(address.city);
cout<<endl;
inout.open("MEMBER.DAT ",ios::out|ios::app|ios::binary);
inout.write((char*)&supp,sizeof(supp));
inout.close();
cout <<"\n RECORD IS SUCCESFULLY ENTERED .. ";
}

}

void member1::display_data()
{
clrscr();
textcolor(BLACK);
textbackground(WHITE);
gotoxy(22,1);cprintf("Y U G V E E N A   L I B R A R Y   S Y S T  E M");
gotoxy(22,2);cprintf("          MEMBER'S INFORMATION                ");

gotoxy(2,5);cprintf("  CODE          MEM_NAME          HOUSE NO                          CITY");

textcolor(WHITE);
textbackground(BLACK);
int i=7;
inout.open("MEMBER.DAT ",ios::in|ios::binary);
inout.seekg(0,ios::beg);

while(inout.read((char*)&supp,sizeof(supp)))
{
gotoxy(2,i);cout<<mem_id;
gotoxy(18,i);cout<<mem_name;
gotoxy(37,i);cout<<address.hou_no;


gotoxy(69,i);cout<<address.city;
i=i+1;
delay(100);
}
inout.close();

}


void member1::m_disp()
{
textcolor(BLACK);
textbackground(WHITE);
gotoxy(22,1);cprintf("Y U G V E E N A   L I B R A R Y   S Y S T  E M");
gotoxy(22,2);cprintf("          MEMBER'S INFORMATION                ");
gotoxy(2,5);cprintf( "  CODE          MEM_NAME          HOUSE NO                         CITY");
textcolor(WHITE);
textbackground(BLACK);

gotoxy(2,7);cout<<supp.mem_id;
gotoxy(18,7);cout<<supp.mem_name;
gotoxy(37,7);cout<<address.hou_no;
gotoxy(69,7);cout<<address.city;
cout <<"\n RECORD MATCHED .. ";

}







void member1::modification()
{
int et,flag=0,i;
char ch;
textcolor(BLACK);
textbackground(WHITE);
gotoxy(22,1);cprintf("Y U G V E E N A   L I B R A R Y   S Y S T  E M");
gotoxy(22,2);cprintf("          MEMBER'S INFORMATION                ");
gotoxy(2,5);cprintf("  CODE          MEM_NAME          HOUSE NO                          CITY");
textcolor(WHITE);
textbackground(BLACK);




cout <<"\nWHICH RECORD OF MEMBER DO YOU WANT TO MODIFY .. ";
fflush(stdin);
cin >>et;
fflush(stdin);
flag=0;
inout.open("MEMBER.DAT ",ios::in|ios::out|ios::binary);
inout.seekg(0,ios::beg);
inout.read((char*)&supp,sizeof(supp));

while (!inout.eof())
{
if(et==supp.mem_id)
{
gotoxy(2,7);cout<<mem_id;
gotoxy(18,7);cout<<mem_name;
gotoxy(37,7);cout<<address.hou_no;
gotoxy(69,7);cout<<address.city;

flag=1;
cout <<"\n YOU WANT TO MODIFY THIS RECORD ..";
cin >>ch;
if (ch=='y' || ch=='Y')
{
clrscr();
textcolor(BLACK);
textbackground(WHITE);
gotoxy(22,1);cprintf("Y U G V E E N A   L I B R A R Y   S Y S T  E M");
gotoxy(22,2);cprintf("          MEMBER'S INFORMATION                ");
gotoxy(2,5);cprintf( "  CODE          MEM_NAME          HOUSE NO                         CITY");
textcolor(WHITE);
textbackground(BLACK);

gotoxy(2,7);cout<<mem_id;
gotoxy(18,7);gets(mem_name);
gotoxy(37,7);cin>>address.hou_no;
gotoxy(69,7);gets(address.city);

inout.seekp(inout.tellg()-sizeof(supp),ios::beg);
inout.write((char*)&supp,sizeof(supp));
gotoxy( 20,10);cout<<"\nRECORD IS MODIFIED ";
}
}
inout.read((char*)&supp,sizeof(supp));
}
inout.close();
if(flag==0)
{



cout<<"RECORD NOT MATCHED";
cout<<"PRESS ANY KEY TO CONTINUE.....";
getch();
}
}
//*****************************
void member1::dele()
{
int et,flag;
clrscr();
textcolor(BLACK);
textbackground(WHITE);
gotoxy(22,1);cprintf("Y U G V E E N A   L I B R A R Y   S Y S T  E M");
gotoxy(22,2);cprintf("          MEMBER'S INFORMATION                ");
gotoxy(2,5);cprintf( "  CODE          MEM_NAME          HOUSE NO                         CITY");
textcolor(WHITE);
textbackground(BLACK);

cout <<"\n WHICH RECORD DO YOU WANT TO DELETE = ";
fflush(stdin);
cin >>et;
fflush(stdin);
flag=0;
inout.open("MEMBER.DAT ",ios::in|ios::binary);
inout.seekg(0,ios::beg);
inout.read((char*)&supp,sizeof(supp));
while (!inout.eof())
{
if (et==supp.mem_id)
{
flag=1;
textcolor(BLACK);
textbackground(WHITE);
gotoxy(22,1);cprintf("Y U G V E E N A   L I B R A R Y   S Y S T  E M");
gotoxy(22,2);cprintf("          MEMBER'S INFORMATION                ");
gotoxy(2,5);cprintf( "  CODE          MEM_NAME          HOUSE NO                         CITY");
textcolor(WHITE);
textbackground(BLACK);
gotoxy(2,7);cout<<mem_id;
gotoxy(18,7);cout<<mem_name;
gotoxy(37,7);cout<<address.hou_no;
gotoxy(69,7);cout<<address.city;

cout <<"\n RECORD EXIST ";
cout <<"\n PRESS ANY KEY TO DELETE THIS RECORD....";

getch();
}
inout.read((char*)&supp,sizeof(supp));
}
inout.close();
in.open("TEMPORE ",ios::out|ios::binary);
in.seekp(0,ios::beg);
inout.open("MEMBER.DAT ",ios::in|ios::binary);
inout.seekg(0,ios::beg);
inout.read((char*)&supp,sizeof(supp));
while(!inout.eof())
{
fflush(stdin);
fflush(stdout);
if (supp.mem_id!=et)
{
in.write((char*)&supp,sizeof(supp));
}
inout.read((char*)&supp,sizeof(supp));
}
inout.close();
in.close();
remove("MEMBER.DAT ");
rename("TEMPORE ","MEMBER.DAT ");
cout <<"\n RECORD DELETED ";
if(flag==0)
{
cout <<"\n RECORD NOT EXIST .. ";
}
}

void store::getdata()
{
char ch;
clrscr();
status='A';
textcolor(BLACK);
textbackground(WHITE);
gotoxy(22,1);cprintf("Y U G V E E N A   L I B R A R Y   S Y S T  E M");
gotoxy(22,2);cprintf("               BOOKS INFORMATION              ");
gotoxy(2,5);cprintf(" BOOK CODE    BOOK NAME       BOOK PRICE   BOOK AUTHOR        BOOK STATUS");
textcolor(WHITE);
textbackground(BLACK);
inout.open("BOOKS.DAT",ios::in);
inout.read((char *)&stor,sizeof(stor));
if (!inout)
{
stor.bookcode=500;


gotoxy(2,7);cout<<stor.bookcode;
gotoxy(17,7);gets(bookname);
gotoxy(36,7);cin>>bookprice;
gotoxy(48,7);gets(author);
gotoxy(69,7);cout<<status;
inout.close();
inout.open("BOOKS.DAT",ios::out|ios::app|ios::binary);
inout.write((char*)&stor,sizeof(store));
inout.close();
cout <<"\n RECORD ENTERED ..";
}
else
{
while (!inout.eof())
{
inout.read((char*)&stor,sizeof(store));
}
inout.close();
stor.bookcode=stor.bookcode+1;
gotoxy(2,7);cout<<stor.bookcode;
gotoxy(17,7);gets(bookname);
gotoxy(36,7);cin>>bookprice;
gotoxy(48,7);gets(author);
gotoxy(69,7);cout<<status;

inout.open("BOOKS.DAT",ios::out|ios::app|ios::binary);
inout.write((char*)&stor,sizeof(store));
inout.close();
cout <<"\n RECORD ENTERED ..";
}
}


void store::displaydata()
{
//  clrscr();
clrscr();
//cout <<"ALL STORE RECORDS OF BOOK ARE :-";
inout.open("BOOKS.DAT",ios::in|ios::binary);
fflush(stdin);
inout.seekg(0);
textcolor(BLACK);
textbackground(WHITE);
gotoxy(22,1);cprintf("Y U G V E E N A   L I B R A R Y   S Y S T  E M");
gotoxy(22,2);cprintf("               BOOKS - - INFORMATION          ");
gotoxy(2,5);cprintf(" BOOK CODE    BOOK NAME       BOOK PRICE   BOOK AUTHOR       *BOOK STATUS");
textcolor(WHITE);
textbackground(BLACK);


int i=7;
while(inout.read((char*)&stor,sizeof(store)))
{
gotoxy(2,i);cout<<stor.bookcode;
gotoxy(17,i);cout<<bookname;
gotoxy(36,i);cout<<bookprice;
gotoxy(48,i);cout<<author;
gotoxy(69,i);cout<<status;
delay(100);
i++;
//stor.displaydata();
//getch();
}
inout.close();

}

void store::b_disp()
{

clrscr();
int rec;
textcolor(BLACK);
textbackground(WHITE);
gotoxy(22,1);cprintf("Y U G V E E N A   L I B R A R Y   S Y S T  E M");
gotoxy(22,2);cprintf("            BOOKS - - INFORMATION              ");
gotoxy(2,5);cprintf(" BOOK CODE    BOOK NAME       BOOK PRICE   BOOK AUTHOR       *BOOK STATUS");
textcolor(WHITE);
textbackground(BLACK);

textcolor(BLACK);
textbackground(WHITE);
gotoxy(22,1);cprintf("Y U G V E E N A   L I B R A R Y   S Y S T  E M");
gotoxy(22,2);cprintf("            BOOKS - - INFORMATION              ");
gotoxy(2,5);cprintf(" BOOK CODE    BOOK NAME       BOOK PRICE   BOOK AUTHOR       *BOOK STATUS");
textcolor(WHITE);
textbackground(BLACK);
gotoxy(2,7);cout<<bookcode;
gotoxy(17,7);cout<<bookname;
gotoxy(36,7);cout<<bookprice;
gotoxy(48,7);cout<<author;
gotoxy(69,7);cout<<status;

}



void store :: deletion()
{
clrscr();
int rec,flag=0;
textcolor(BLACK);
textbackground(WHITE);
gotoxy(22,1);cprintf("Y U G V E E N A   L I B R A R Y   S Y S T  E M");
gotoxy(22,2);cprintf("           BOOKS - - INFORMATION              ");
gotoxy(2,5);cprintf(" BOOK CODE    BOOK NAME       BOOK PRICE   BOOK AUTHOR       *BOOK STATUS");
textcolor(WHITE);
textbackground(BLACK);

cout <<"\n WHICH RECORD YOU WANT TO DELETE ";
fflush(stdin);
cin >>rec;
flag=0;
inout.open("BOOKS.DAT",ios::in|ios::binary);
inout.seekg(0,ios::beg);
inout.read((char*)&stor,sizeof(store));
clrscr();
while (!inout.eof())
{
if (rec==stor.bookcode)
{
flag=1;
char ch;
textcolor(BLACK);
textbackground(WHITE);
gotoxy(22,1);cprintf("Y U G V E E N A   L I B R A R Y   S Y S T  E M");
gotoxy(22,2);cprintf("           BOOKS - - INFORMATION              ");
gotoxy(2,5);cprintf(" BOOK CODE    BOOK NAME       BOOK PRICE   BOOK AUTHOR       *BOOK STATUS");
textcolor(WHITE);
textbackground(BLACK);
gotoxy(2,7);cout<<bookcode;
gotoxy(17,7);cout<<bookname;
gotoxy(36,7);cout<<bookprice;
gotoxy(48,7);cout<<author;
gotoxy(69,7);cout<<status;

cout <<"\n RECORD EXIST ";
cout <<"\n ARE YOU SURE THAT YOU WANT TO DELETE IT ";
cout <<"\n ENTER CHOICE (Y/N)=  ";
cin >>ch;
if (ch=='n' || ch=='N')
break;
}

inout.read((char*)&stor,sizeof(store));
}
inout.close();
inout.open("BOOKS.DAT",ios::in|ios::binary);
in.open("TEMPORE ",ios::out|ios::binary);
inout.seekg(0,ios::beg);
in.seekp(0,ios::beg);
inout.read((char*)&stor,sizeof(store));
while (!inout.eof())
{
if (stor.bookcode!=rec)
{
in.write((char*)&stor,sizeof(store));
}
inout.read((char*)&stor,sizeof(store));
}
inout.close();
in.close();
remove("BOOKS.DAT");
rename("TEMPORE ","BOOKS.DAT");
cout <<"\n RECORD DELETED ..";
cout <<"\n PRESS ANY KEY TO CONTINUE ..";
getch();
if (flag==0)
{
cout <<"\n RECORD NOT EXIST ";
cout <<"\n PRESS ANY KEY TO CONTINUE ..";
getch();
}
}


void store::mod_data()
{
clrscr();
int rec,flag=0;
char ch;
textcolor(BLACK);
textbackground(WHITE);
gotoxy(22,1);cprintf("Y U G V E E N A   L I B R A R Y   S Y S T  E M");
gotoxy(22,2);cprintf("           BOOKS - - INFORMATION              ");
gotoxy(2,5);cprintf(" BOOK CODE    BOOK NAME       BOOK PRICE   BOOK AUTHOR       *BOOK STATUS");
textcolor(WHITE);
textbackground(BLACK);

cout <<"\n WHICH RECORD DO YOU WANT TO MODIFY ..";
fflush(stdin);
cin >>rec;


flag=0;
clrscr();
inout.open("BOOKS.DAT",ios::in|ios::out|ios::binary);
inout.seekg(0,ios::beg);
inout.read((char*)&stor,sizeof(store));
fflush(stdin);
while(!inout.eof())
{
if(rec==stor.bookcode)
{
flag=1;
textcolor(BLACK);
textbackground(WHITE);
gotoxy(22,1);cprintf("Y U G V E E N A   L I B R A R Y   S Y S T  E M");
gotoxy(22,2);cprintf("           BOOKS - - INFORMATION              ");
gotoxy(2,5);cprintf(" BOOK CODE    BOOK NAME       BOOK PRICE   BOOK AUTHOR       *BOOK STATUS");
textcolor(WHITE);
textbackground(BLACK);
gotoxy(2,7);cout<<stor.bookcode;
gotoxy(17,7);cout<<bookname;
gotoxy(36,7);cout<<bookprice;
gotoxy(48,7);cout<<author;
gotoxy(69,7);cout<<status;

cout <<"\n DO YOU WANT TO MODIFY THIS RECORD (Y/N) .....";
fflush(stdin);
cin >>ch;
clrscr();
if (ch=='Y'||ch=='y')
{

textcolor(BLACK);
textbackground(WHITE);
gotoxy(22,1);cprintf("Y U G V E E N A   L I B R A R Y   S Y S T  E M");
gotoxy(22,2);cprintf("           BOOKS - - INFORMATION              ");
gotoxy(2,5);cprintf(" BOOK CODE    BOOK NAME       BOOK PRICE   BOOK AUTHOR       *BOOK STATUS");
textcolor(WHITE);
textbackground(BLACK);
gotoxy(2,7);cout<<bookcode;
gotoxy(17,7);gets(bookname);
gotoxy(36,7);cin>>bookprice;
gotoxy(48,7);gets(author);
gotoxy(69,7);cout<<status;
inout.seekp(inout.tellg()-sizeof(store),ios::beg);
inout.write((char*)&stor,sizeof(store));


cout <<"\n RECORD IS MODIFIED ";
}
break;
}
inout.read((char*)&stor,sizeof(store));
}
inout.close();
if (flag==0)
{
cout <<"RECORD NOT MATCHED ..";
cout <<"PRESS A KEY TO CONTINUE ........";
getch();
}
}





void main()
{
char s[20];
screen();
char st[]={"      I EXPRESS MY THANKS TO MY COMPUTER TEACHER SIR PRAGYA RAJZHA"
" FOR HER CO-OPERATION AND PATIENCE.UNDER HIS GUIDANCE I AM ABLE TO COMPL"
"ETE THIS PROJECT.I ALSO EXPR--ESS MY GRATITUDE TO MY PRINCIPAL FRANCIS PANDEY"
" FOR HIS KIND NATURE AND PATIEN--CE SHOWN TOWARDS MY SCHEDULE WORK."};
int i=0;
clrscr();
textcolor(YELLOW);
textbackground(GREEN);
gotoxy(25,7);cprintf(" A K N O W L E D G E M E N T ");
textcolor(YELLOW);
textbackground(BLUE);
gotoxy(23,8);cprintf("---------------------------------");
textcolor(WHITE);
textbackground(BLACK);

gotoxy(1,10);
while(st[i]!='\0')
{
cout<<st[i];
if(i>0)
delay(50);
i++;
}
textcolor(WHITE);


textbackground(BLACK);
gotoxy(50,19);cout<<"BY....";
music();
gotoxy(50,20);cout<<" MAYANK ";
music();


getch();
main_menu();
}

void main_menu()
{
char ch;
int choice;
do
{
clrscr();
int j=6,l=61;
for(int k=1;k<27;k++)
{
gotoxy(k,j);
cout<<" M A I N - ";
gotoxy(l,j);
cout<<" - M E N U ";
sound(500/k*l);
delay(50);
l--;
}
nosound();
textcolor(YELLOW);
textbackground(BLUE);
gotoxy(18,1);cprintf("Y U G V E E N A   L I B R A R Y   S Y S T  E M");
textcolor(WHITE);
textbackground(BLACK);
gotoxy (30,9);
cout <<"1. BOOK DETAIL ";
gotoxy (30, 10);
cout <<"2. MEMBER DETAIL ";
gotoxy (30,11);
cout <<"3. ISSUE BOOK ";
gotoxy (30,12);
cout <<"4. EXIT ";
gotoxy (30,13);
cout <<"\n ENTER CHOICE .....";
cin >>choice;
switch(choice)
{
case 1:



book();
break;
case 2:
member();
break;
case 3:
issued();
break;
case 4:
quit();
exit(0);
break;
}
cout <<"\n DO YOU WANT TO RETURN TO MAIN-MENU .....";
cin >>ch;
} while (ch=='y' || ch=='Y');
}

void music()
{
int i=2,k=5,p=0;
while(p!=1)
{
i=2;
while(i!=10)
{
sound((700*k)/i);
i+=2;
delay(150);
}
p++;
}
nosound();
}
void quit()
{
for(int i=25;i>1;i--)
{
gotoxy(1,i);
cout<<"                       B Y E  - - B Y E                          ";
cout<<"                                                                 ";
delay(200);
}
}

void screen()
{
int j;
clrscr();


gotoxy (25,1);
textcolor(YELLOW);
textbackground(BLUE);
cprintf("L I B R A R Y  - - M A N A G E M E N T");
textcolor(WHITE);
textbackground(BLACK);
cout<<endl;
for(int i=0;i<75;i++)
cout<<"*";
gotoxy (5,2);
textcolor(YELLOW);
textbackground(GREEN);
gotoxy(15,3);cprintf("THIS IS THE PROJECT TO ISSUE & RECEIVE BOOKS OF LIBRARY");
textcolor(WHITE);
textbackground(BLACK);

gotoxy (1,4);
for (j=0;j<75;j++)
{
cout <<"*";
}
cout <<"\n";
gotoxy (1,6);
sound(500);
cout <<"L";delay(100);
gotoxy (3,7);
sound(500);
cout <<"I";delay(100);
gotoxy (5,8);
sound(500);
cout <<"B";delay(100);
gotoxy (7,9);
sound(500);
cout <<"R";delay(100);
gotoxy (9,10);
sound(500);
cout <<"A";delay(100);
gotoxy (11,11);
sound(500);
cout <<"R";delay(100);
gotoxy (13,12);
sound(500);
cout <<"Y";delay(100);
gotoxy (15,13);
sound(500);
cout <<"*";delay(100);
gotoxy (17,14);
sound(500);
cout <<"S";delay(100);
gotoxy (19,15);


sound(500);
cout <<"Y";delay(100);
gotoxy (21,16);
sound(500);
cout <<"S";delay(100);
gotoxy (23,17);
sound(500);
cout <<"T";delay(100);
gotoxy (25,18);
sound(500);
cout <<"E";delay(100);
gotoxy (27,19);
sound(500);
cout <<"M";delay(100);
gotoxy (29,20);
sound(500);
cout <<" ";delay(100);
gotoxy (31,21);
sound(500);
cout <<" ";delay(100);
gotoxy (58,15);
sound(500);
cout <<"SUPERVISED BY :";delay(100);
gotoxy (59,16);
sound(500);
cout <<"MS.PRAGYA RAJZHA ....";delay(100);
gotoxy (58,18);
sound(500);
cout <<"PRESENTED BY ....";delay(100);
gotoxy (59,19);
sound(500);
cout <<"MAYANK  ";delay(100);
gotoxy (59,20);
sound(500);
cout <<"X Y Z ";delay(100);
gotoxy (48,22);
sound(500);
cout <<"PRESS ANY KEY TO CONTINUE ....";delay(100);
nosound();
getch();

}


void book()
{
int flag=0;
char c,ch;
do
{
clrscr();



int ch1,it,rec;
int j=8,l=61;
for(int k=1;k<27;k++)
{
gotoxy(k,j);cout<<" B O O K - ";
gotoxy(l,j);cout<<" - M E N U ";
sound(500/k*l);
delay(50);
l--;
}
nosound();
textcolor(YELLOW);
textbackground(BLUE);
gotoxy(18,1);cprintf("Y U G V E E N A   L I B R A R Y   S Y S T  E M");
textcolor(WHITE);
textbackground(BLACK);
gotoxy (30,11);
cout <<"1. ADD BOOK ";
gotoxy (30,12);
cout <<"2. DELETE BOOK ";
gotoxy (30,13);
cout <<"3. MODIFY BOOK ";
gotoxy (30,14);
cout <<"4. DISPLAY ";
gotoxy (30,15);
cout <<"5. REPORT ";
gotoxy (30,16);
cout <<"6. RETURN ";
gotoxy (30,17);
cout <<"ENTER CHOICE ";
cin >>ch1;
switch(ch1)
{
case 1:
stor.getdata();
break;
case 2:
stor.deletion();
break;
case 3:
stor.mod_data();
break;
case 4 :
int rec;
clrscr();
textcolor(YELLOW);
textbackground(BLUE);
gotoxy(22,1);cprintf("Y U G V E E N A   L I B R A R Y   S Y S T  E M");


gotoxy(22,2);cprintf("               BOOKS - - INFORMATION              ");
gotoxy(2,5);cprintf(" BOOK CODE    BOOK NAME       BOOK PRICE   BOOK AUTHOR       *BOOK STATUS");
textcolor(WHITE);
textbackground(BLACK);
cout <<"\n WHICH RECORD YOU WANT TO VIEW :-  ";
fflush(stdin);
cin >>rec;
flag=0;
inout.open("BOOKS.DAT",ios::in|ios::binary);
inout.seekg(0,ios::beg);
inout.read((char*)&stor,sizeof(store));
clrscr();
while (!inout.eof())
{
if (rec==stor.bookcode)
{
flag=1;
char ch;
stor.b_disp();
cout <<"\n RECORD EXIST ";
break;
}
inout.read((char*)&stor,sizeof(store));
}
inout.close();
if(flag==0)
gotoxy(35,15);cprintf("RECORD NOT EXIST");
break;
case 5:
stor.displaydata();
break;
case 6:
clrscr();
main_menu();
break;
}//END OF SWITCH CASE
cout <<"\n DO YOU WANT TO GO TO BOOK-MENU......";
fflush(stdin);
cin >>c;
}while (c=='y' || c=='Y');
}


//MEMBER FUNCTION FOR MEMBER'S DETAILS
void member()
{
int flag=0;
char c,ch2;
do


{
clrscr();
int ch2,df,et;
int i,j=9,l=56;

for(int k=1;k<20;k++)
{
gotoxy(k,j);cout<<" M E M B E R  - ";
gotoxy(l,j);cout<<" - M E N U ";
sound(500/k*l);
delay(50);

l--;
}
nosound();
textcolor(YELLOW);
textbackground(BLUE);
gotoxy(18,1);cprintf("Y U G V E E N A   L I B R A R Y   S Y S T  E M");
textcolor(WHITE);
textbackground(BLACK);

gotoxy (30,12);
cout <<"1. ADD MEMBER RECORD ";
gotoxy (30,13);
cout <<"2. MODIFICATION ";
gotoxy (30,14);
cout <<"3. DISPLAY ";
gotoxy (30,15);
cout <<"4. REPORT ";
gotoxy (30,16);
cout <<"5. DELETION ";
gotoxy (30,17);
cout <<"6. RETURN ";
gotoxy (30,18);
cout <<"\n ENTER YOUR CHOICE .. ";
cin >>ch2;
switch(ch2)
{
case 1:
clrscr();
supp.get_data();
break;
case 2:
clrscr();
supp.modification();
break;
case 3:
clrscr();
textcolor(YELLOW);
textbackground(BLUE);


gotoxy(22,1);cprintf("Y U G V E E N A   L I B R A R Y   S Y S T  E M");
gotoxy(22,2);cprintf("          MEMBER'S INFORMATION                ");
gotoxy(2,5);cprintf( "  CODE          MEM_NAME          HOUSE NO               CITY");
textcolor(WHITE);
textbackground(BLACK);
cout <<"\n WHICH RECORD YOU WANT TO VIEW .. ";
cin >>et;
flag=0;
inout.open("MEMBER.DAT ",ios::in|ios::binary);
inout.seekg(0,ios::beg);
inout.read((char*)&supp,sizeof(supp));
while (!inout.eof())
{
if (et==supp.mem_id)
{
supp.m_disp();
flag=1;
break;
}
inout.read((char*)&supp,sizeof(supp));
}
inout.close();
if (flag==0)
{
cout <<"\n RECORD NOT MATCHED .. ";
cout <<"\n PRESS ANY KEY TO CONTINUE .. ";
getch();
}
break;
case 4:
clrscr();
supp.display_data();
break;
case 5:
clrscr();
supp.dele();
break;
case 6:
clrscr();
main_menu();
break;
}
   cout <<"\n DO YOU WANT TO GO TO MEMBER - MENU.......";
cin >>c;
}
while (c=='y' || c=='Y');
//  return 0;
}


void issued()
{
int ch3,flag,sl;
clrscr();
char ch;
int s;

do
{
clrscr();
int i,j=6,l=63;
for(int k=1;k<26;k++)
{
gotoxy(k,j);cout<<" I S S U E   - ";
gotoxy(l,j);cout<<" - M E N U ";
sound(500/k*l);
delay(50);
l--;
}
nosound();

textcolor(YELLOW);
textbackground(BLUE);
gotoxy(18,1);cprintf("Y U G V E E N A   L I B R A R Y   S Y S T  E M");
textcolor(WHITE);
textbackground(BLACK);
gotoxy (30,11);
cout <<"1. BOOK ISSUE ";
gotoxy (30,12);
cout <<"2. BOOK RETURN ";
gotoxy (30,13);
cout <<"3. RETURN ";
cout <<"\n ENTER YOUR CHOICE .. ";
cin >>ch3;
name();
int ite,n;
switch(ch3)
{
case 1:
clrscr();
int bflag=0;
flag=0;
int sp;
int f=0;
cout <<"\n ENTER THE MEMBER ID :-  ";
cin >>s;
inout.open("MEMBER.DAT ",ios::in|ios::binary);
inout.seekg(0,ios::beg);
while(inout.read((char*)&supp,sizeof(supp)))
{


if (supp.mem_id==s)
{
flag=1;
}
}
if(flag==0)
{
cout<<"MEMBER NOT EXIST IN LIST";
inout.close();

break;
}
inout.close();

//*************************

cout <<"\n WHICH BOOK YOU WANT TO ISSUE .. ";
cin >>sl;
inout.open("BOOKS.DAT",ios::in|ios::out|ios::binary);
inout.seekg(0,ios::beg);
inout.read((char*)&stor,sizeof(store));
while(!inout.eof())
{
if (sl==stor.bookcode)
{
stor.b_disp();
bflag=1;
if (stor.status=='N')
{
cout <<"\n SORRY !!! BOOK ALREADY ISSUED ";
getch();
break;
}
else
cout <<"\n BOOK EXIST ";

cout <<"\n DO YOU WANT THIS BOOK .. ";
cin >>ch;
if (ch=='y' || ch=='Y')
{
stor.status='N';
inout.seekp(inout.tellg()-sizeof(store),ios::beg);
inout.write((char*)&stor,sizeof(store));
inout.close();
getch();
break;
}

}
inout.read((char*)&stor,sizeof(stor));
}


if (bflag==0)
{
cout <<"\n BOOK DOES NOT EXIST .. ";
inout.close();
}
break;
case 2:
clrscr();
flag=0;
f=0;
cout <<"\n ENTER THE BOOK NUMBER :-  ";
fflush(stdin);
cin >>sp;
inout.open("BOOKS.DAT",ios::in|ios::out|ios::binary);
inout.read((char*)&stor,sizeof(store));
while (!inout.eof())
{
if (sp==stor.bookcode)
{
f=1;
stor.b_disp();
cout <<"\n DO YOU WANT TO RETURN THIS BOOK .. ";
cin >>ch;
if (ch=='y' || ch=='Y')
{
stor.status='A';
inout.seekp(inout.tellg()-sizeof(store),ios::beg);
inout.write((char*)&stor,sizeof(store));
}
}
inout.read((char*)&stor,sizeof(store));
}

inout.close();
if(f==0)
cout<<"BOOK CODE DOES NOT EXIST";
break;
case 3 :
clrscr();
main_menu();
break;
}
}
while (ch=='y' || ch=='Y');

}


//*******************
