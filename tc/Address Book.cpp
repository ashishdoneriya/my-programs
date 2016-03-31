#include<fstream>
#include<iostream>
#include<conio.h>
#include<ctype.h>
//#include<iomanip.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<graphics.h>
using namespace std;
void welcome_screen();
void welcome_screen()
     {
	clrscr();
	outtextxy(20,10,"**************** W E L C O M E  *********************** ");
	outtextxy(25,12,"*** C A M P I O N    S C H O O L *** " );
	outtextxy(20,14," T E L E P H O N E  M A N A G E M E N T  S O F T W A R E  ");
	outtextxy(38,16," D O N E  B Y :  ");
	outtextxy(50,18," Navi Arora ");
	outtextxy(50,20,"");
	
	setfontcolor(WHITE);
	outtextxy(40,30," *** PRESS ANY KEY TO CONTINUE***");
	getch();
	return;
     }
class directory
     {
       public:
	       int record;
	       long pn1;
	       char pn2[10];
	       int age;
	       char address1[50];
	       char address2[50];
	       char occupation[20];
	       char name[20];
	       char emailadd[25];
	       char internetadd[25];
	       void modification();
	       void addition();
	       void deleate();
	       void menu();
	       void search();
	       void view1();
	       void init();
	       void display();
	       void view();
	       char check(char *);
	       int test();
	    }obj;
void directory::addition()  //ADDING  INFORMATION
    {
      ofstream fout;
      fout.open("ashish",ios::out|ios::app);
      init();
      fout.write((char*)&obj,sizeof(obj));
      fout.close();
    }
int directory::test()    //FIND NO. OF RECORDS
    {
      ifstream fin;
      fin.open("ashish");
      fin.seekg(0,ios::end);
      int n;
      n=fin.tellg()/sizeof(obj);
      cout<<" \n NUMBER OF RECORDS = "<<n ;
      return n ;
    }
void directory::search()  //SEARCHING FOR A PARTICULAR NUMBER
    {
      ifstream fin;
      fin.open("ashish");
      if(fin.fail())
	{
	  cout<<" \n FILE NOT FOUND ";
	  getch();
	  return;
	}
      clrscr();
      setbkcolor(BLACK);
      setfontcolor(RED);
      outtextxy(30,1," [SEARCHING] ");
      cout<<" \n ENTER PHONE NUMBER TO BE SEARCHED : ";
      long pn;
      cin>>pn;
      int n;
      n=test();
      for(int i=0;i<n;i++)
	{
	  fin.read((char*)&obj,sizeof(obj));
	  if(pn==pn1)
	    {
	      view1();
	      return;
	    }
	}
      if(fin.eof())
	{
	  cout<<" \n RECORD NOT FOUND ";
	}
    }
void directory::init()  // ENTERING THE DETAILS
    {

      clrscr();
      char ch;
      setcolor(BLACK);
      outtextxy(30,100," [ADDITION] ");
      //textcolor(BLACK);
      cout<<" \n ENTER HOUSE PHONE NUMBER : ";
      cin>>pn1;
      cout<<" \n ENTER OFFICE PHONE NUMBER : ";
      cin>>pn2;
      // ch=cin.get();
      cin.get(ch);
      cout<<" \n ENTER NAME : ";
      cin.getline(name,20,'\n');
      cout<<" \n ENTER THE OCCUPATION : ";
      cin.getline(occupation,20,'\n');
      cout<<" \n ENTER HOUSE ADDRESS : ";
      cin.getline(address1,50,'\n');
      cout<<" \n ENTER OFFICE ADDRESS : ";
      cin.getline(address2,50,'\n');
      cout<<" \n ENTER EMAIL ADDRESS : ";
      cin.getline(emailadd,25,'\n');
      cout<<" \n ENTER INTERNET ADDRESS : ";
      cin.getline(internetadd,25,'\n');
    }

void directory::view1() //TO DISPLAY ALL THE RECORDS
    {
      cout<<"\n";
      cout<<" PHONE NUMBER1 : "<<obj.pn1<<"\n";
      cout<<" PHONE NUMBER2 : "<<obj.pn2<<"\n";
      cout<<" NAME : "<<obj.name<<"\n";
      cout<<" HOUSE ADDRESS : "<<obj.address1<<"\n";
      cout<<" OCCUPATION : "<<obj.occupation<<"\n";
      cout<<" OFFICE ADDRESS : "<<obj.address2<<"\n";
      cout<<" EMAIL ADDRESS : "<<obj.emailadd<<"\n";
      cout<<" INTERNET ADDRESS : "<<obj.internetadd<<"\n";
      getch();
    }
void directory::modification() //TO MODIFY ANY DATA IN  THE RECORD IF NECESSARY
   {
     clrscr();
    // setcolor(BLACK+BLINK);
    outtextxy(30,1," [ MODIFICATION ] ");
     setbkcolor(BLACK);
     long pn;
     int n,i;
     ifstream fin;
     ofstream fout;
     fin.open("ashish");
     if(fin.fail())
       {
	 cout<<"\n FILE NOT FOUND !";
	 fout.close();
	 exit(-1);
       }
    fout.open("new");
    n=test();
    if(n==0)
      {
	cout<<"\n FILE IS EMPTY ! ";
	getch();
	return;
      }
   while(fin.good())
      {
	fin.read((char*)&obj,sizeof(obj));
	fout.write((char*)&obj,sizeof(obj));
      }
   fin.close();
   fout.close();
   fout.open("ashish",ios::trunc);
   fin.open("new");
   if(fin.fail())
     {
      cout<<"\n FILE NOT FOUND !";
      exit(-1);
     }
   char ch;
   cout<<"\n ENTER PHONE NUMBER :";
   cin>>pn;
   ch=cin.get();
//   cin.get(ch);
   for(i=0;i<n;i++)
	{
	   fin.read((char*)&obj,sizeof(obj));
	   char d;
	   if(pn==pn1)
	      {
		view1();
		d=check("HOUSE PHONE NUMBER ");
		if((d=='y') || (d=='Y'))
		  {
		    cout<<"\n ENTER NEW PHONE NUMBER :";
		    cin>>pn1;
		    ch=cin.get();
		  //  cin.get(ch);
		  }
		if(check("OFFICE PHONE NUMBER ")=='Y')
		  {
		    cout<<"\n ENTER NEW PHONE NUMBER :";
		    cin>>pn2;
		   ch=cin.get();
		 // cin.get(ch);
		  }
		if(check("NAME")=='y')
		  {
		    cout<<"\n ENTER NEW NAME : ";
		    cin.getline(name,20,'\n');
		  }
		if(check("HOME ADDRESS")=='y')
		  {
		    cout<<"\n ENTER NEW ADDRESS :";
		    cin.getline(address1,50,'\n');
		  }
		if(check("OFFICE ADDRESS")=='y')
		  {
		    cout<<"\n ENTER NEW ADDRESS :";
		    cin.getline(address2,50,'\n');
		  }
		if(check("EMAIL ADDRESS:")=='y')
		  {
		    cout<<"\n ENTER NEW MAIL ADDRESS :";
		    cin.getline(emailadd,25,'\n');
		  }
		if(check("INTERNET ADDRESS")=='y')
		  {
		    cout<<"\n ENTER NEW INTERNET ADDRESS :";
		    cin.getline(internetadd,25,'\n');
		  }
	      }
	   fout.write((char*)&obj,sizeof(obj));
	}
   fout.close();
   fin.close();
    }
char  directory::check(char *s)
    {
       cout<<"\n MODIFY \t "<<s<<"\t"<<"Y/N";
       char ch;
      ch =getch();
      //cin.get(ch);
      if((ch=='y')||(ch=='Y'))
	return 'y';
       else
	return 'n';
    }
void  directory::deleate()
    {
       clrscr();
       //window(1,1,80,25);
       setcolor(BLACK);
       outtextxy(30,1,"[DELETION]");
       long pn;
       int n,i;
       ifstream fin;
       ofstream fout;
       fin.open("ashish");
       if(fin.fail())
	{
	  cout<<"\n FILE NOT FOUND ! ";
	  getch();
	  return;
	}
       fout.open("new");
       n=test();
       if(n==0)
	{
	  cout<<"\n FILE IS EMPTY ! ";
	  getch();
	  return;
	}
      for(i=0;i<n;i++)
	{
	  fin.read((char*)&obj,sizeof(obj));
	  fout.write((char*)&obj,sizeof(obj));
	}
      fin.close();
      fout.close();
      fout.open("meera",ios::trunc);
      fin.open("new");
      if(fin.fail())
	{
	  cout<<"\n FILE NOT FOUND ! ";
	  getch();
	  return;
	}
     cout<<"\n ENTER PHONE NUMBER :";
     cin>>pn;
     for(i=0;i<n;i++)
       {
	 fin.read((char*)&obj,sizeof(obj));
	 if(pn!=pn1)
	    fout.write((char*)&obj,sizeof(obj));
       }
     fout.close();
     fin.close();

    }
 void directory::view()
   {
     ifstream fin;
     int n,j;
     fin.open("ashish");
     if(fin.fail()||fin.bad())
       {
	  cout<<"\n FILE NOT FOUND ! ";
	  getch();
	  return;
       }
     clrscr();
     int i=0;
     n=test();
     for(j=0;j<n;j++)
       {
	 cout<<"\n RECORD "<<i+1<<"\n";
	 fin.read((char*)&obj,sizeof(obj));
	 cout<<"\n PHONE NUMBER1 :"<<obj.pn1<<"\n";
	 cout<<"\n PHONE NUMBER2 :"<<obj.pn2<<"\n";
	 cout<<"\n NAME :"<<obj.name<<"\n";
	 cout<<"\n HOUSE ADDRESS :"<<obj.address1<<"\n";
	 cout<<"\n OCCUPATION :"<<obj.occupation<<"\n";
	 cout<<"\n OFFICE ADDRESS :"<<obj.address2<<"\n";
	 cout<<"\n INTERNET ADDRESS :"<<obj.internetadd<<"\n";
	 cout<<"\n EMAIL ADDRESS : "<<obj.emailadd<<"\n";
	 i+=1;
       }
      fin.close();
      getch();

   }

void  directory::menu()
    {
       char ch;
       clrscr();
       setfontcolor(RED);
       setbkcolor(BLUE);
       outtextxy(30,0," A:ADDITION ");
       outtextxy(30,10," D: DELETION \n  \r ");
       outtextxy(30,20," M:MODIFICATION \n \r ");
       outtextxy(30,30," V:VIEW \n \r ");
       outtextxy(30,40," S:SEARCH \n \r ");
       outtextxy(30,50," E:EXIT \n \r ");
       ch=grgetch();

      switch(ch)
	   {
	     case 'a':
	     case 'A':
		addition();
		break;
	     case 'd' :
	     case 'D' :
		deleate();
		break;
	     case 'm':
	     case 'M':
		modification();
		break;
	     case 'v':
	     case 'V':
		view();
		break;
	     case 's':
	     case 'S':
		search();
		break;
	     case 'e':
	     case 'E':
		system("cls");
		exit(0);
	 }
}
int main()
    {int gd=DETECT,gm;
initgraph(&gd,&gm,"");
      welcome_screen();
      for(;;)
      obj.menu();
      return 0;
   }
