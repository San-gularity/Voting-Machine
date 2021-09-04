#include<fstream>
#include <graphics.h>
#include <dos.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <process.h>
#include <iostream>
//#inlcude<dontinclude.h>
#include <string.h>
void buttons();
void anime();
void password(char user[],char pass[]);
void results();
long int n1=5122,can=1321;

class voter
 {
    int votes;

    public:
    int count;
    char name[30];
    int age;
    char voted;
     //////////////////////////////////////////////////////

    voter()
    {
       voted='N';
       count=0;
       n=5122;
    }
  //  static int coc;
    int n;
    int getvotes()
    {
       return(votes);
    }
    void getdata()
    {
    //   n=n+coc;
    //   coc++;

       cout<<"\nWELCOME VOTER\n";
       cout<<"Your Voter ID is : ";
       cout<<n+1;
       cout<<"\nEnter the student name:";
       gets(name);
       cout<<"\nEnter the student age:";
       cin>>age; n++;
     //  voter();
    }
    void update()
    {
       voted='Y';
    }
    int check()
    {
       return(voted);
    }
    void putdata()
    {
       cout<<"voter id:-\t"<<n;
       cout<<"\nvoter name:-\t"<<name;
       cout<<"\nvoter age:-\t"<<age;
    }
    void putname()
    {
       cout<<"\nCandidate Name :\t"<<name;cout<<"\nID :\t"<<n;
    }

    char *getname()
    {
       return(name);
    }
 }

c1;
//int voter::coc=0;
//long voter::can=1321;

void voterregis()
{
   voter v2;
   char ans='y';
   fstream fout("VOTER.DAT",ios::out|ios::binary);
   while(ans=='y'||ans=='Y')
   {
      cout<<"enter the voter details\n";
      v2.getdata();
      fout.write((char *)&v2,sizeof(v2));
      cout<<"do you want to enter more details\n";
      cin>>ans;
      clrscr();
   }
   fout.close();
}

void candregis()
{
   clrscr();
   long int vt;
   voter v1;
   cout<<"Enter your voter ID...\n";
   cin>>vt;
   ifstream fin("VOTER.DAT",ios::in|ios::binary);
   ofstream fout("CAN.DAT",ios::out|ios::binary);
   while(!fin.eof())
   {
      fin.read((char*)&v1,sizeof(v1));
      if(v1.n==vt)
      {
	 v1.putdata();
	  fout.write((char *)&v1,sizeof(v1));
   cout<<"your candidate ID is..."<<can;
   can++;
	 break;
      }
   }

   fin.close();
   fout.close();
   getch();
}

void anime()
{// clrscr();
 int y=800;

   while(y>=5)
 {delay(1);
  setcolor(BLACK);
  rectangle(y,5,465,600);
  setcolor(BLACK);
  y--;}


 int i=340;
 setcolor(WHITE);
 rectangle(128,201,138,213);
 rectangle(120,190,127,223);

 while(i>=200)
 {setcolor(WHITE);
  rectangle(i,200,i+60,260);
  setcolor(WHITE);
  rectangle(i-60,200,i,220);


  delay(5);
  setcolor(BLACK);
  rectangle(i,200,i+60,260);
  setcolor(BLACK);
  rectangle(i-60,200,i,220);
  i--;
}
  setcolor(WHITE);
  setcolor(WHITE);
  rectangle(i+1,200,i+60+1,260);
  setcolor(WHITE);
  rectangle(i-60+1,200,i+1,220);

   y=800;
   while(y>=5)
 {delay(1);
  setcolor(BLACK);
  rectangle(y,5,465,600);
  setcolor(BLACK);
  y--;
}
	  // getch();

 }
void password(char user[],char pass[])
{
  setcolor(WHITE);
  rectangle(5,5,600,465);
  outtextxy(200,170, "USER NAME:-");
  rectangle(200,260,370,280);
  outtextxy(200,250,"PASSWORD:-");
  rectangle(200,180,370,200);

  for(int j=0;j<strlen(user);j++)
   {
    user[j]=' ';
   }
  for(j=0;j<strlen(pass);j++)
   {
    pass[j]=' ';
   }

  char ch,temp[1]; //int l=0;
  for(int i=0;i<20;i++)
  {
    ch=getch();
    user[i]=ch;
    outtextxy(200,186,user);
    if(ch==' ')
    {break;}
   }

  for(i=0;i<20;i++)
  {
    ch=getch();
    pass[i]=ch;
    outtextxy(200,266,pass);
    if(ch==' ')
    {break;}
   }
   cout<<"yay";
// char user1[20]="voteforjames";
// int pass1[20]={1,2,3,4,5};
 char t='t';
 for(int k=36,o=0,l=104;k<39;k++,o++,l++)
 {
   if((int)pass[o]==k)
   {continue;}
   else if((int)pass[o]==l)
   {t='h';}
   else
   {t='f';break;}
 }
 if(t=='t')
 anime();
 else if(t=='h')
 {
    buttons();
 }
 else
 {
    cout<<"INVALID PASSWORD...LOG IN AGAIN !";
    getch();
    exit(0);
 }
/* if(strcmp(user1,user2)==0)
  {
   if(strcmp(pass1,pass2)==0)
    {anime();}
  }
      */

}

void voting()
{
   int vv;
   clrscr();
 //  int vid=5122;
   voter v6;
   //vote button is pressed//////////////////////////////////
   cout<<"PLEASE ENTER YOUR VOTER ID\n";
   cin>>vv;
   fstream fin("VOTER.DAT",ios::in|ios::binary);
   while(!fin.eof())
   {
      fin.read((char*)&v6,sizeof(v6));
      if(v6.n==vv)
      {
	 v6.putdata();
	// save=v6.n;
	 break;
      }
   }
//   fin.close();
   char c;
   cout<<"\nDO YOU WANT TO CONTINUE VOTING(Y/N)\n";
   cin>>c;
   if(c=='y'||c=='Y')
   {
      char cec;
      cec=v6.check();
      if(cec=='Y')
      {cout<<"person has already voted\n";fin.close();}
      else
      {
	 v6.update();
	 fin.close();
	 voter v3;
	 fstream fin("VOTER.DAT",ios::in|ios::binary);
	 fstream fout("TEMP.DAT",ios::out|ios::binary);
	 while(!fin.eof())
	 {
	    fin.read((char*)&v3,sizeof(v3));
	    if(v3.n==vv)
	    {
	       fout.write((char *)&v3,sizeof(v3));
	    }
	    else
	    {
	       fout.write((char *)&v3,sizeof(v3));
	    }
	 }
	 fin.close();
	 fout.close();
	 remove("VOTER.DAT");
	 rename("TEMP.DAT","VOTER.DAT");
	 getch();
	 clrscr();
	 buttons();
  //	 clrscr();
      }
   }
}
int save=0;

void buttons()
{
   char an='v';
   cout<<"DO YOU WANT TO TALLY OR RESULT...(T/R)";
   cin>>an;
/*   if(an=='v')
   {
   int a=0;
   voter v10;
   ifstream disp("CAN.DAT",ios::in|ios::binary);
   while(!disp.eof())
   {
      disp.read((char*)&v10,sizeof(v10));
      if(!disp.eof())
      {
      cout<<"\nNUMBER-"<<a++;
      v10.putname();
      cout<<"\n";
      }
   }
   int h;
   disp.close();
   cout<<"CHOOSE ...\n";
   cin>>h;
   long pos;
   voter v11;
   fstream diss("CAN.DAT",ios::in|ios::binary|ios::out);
   while(!diss.eof())
   {
      pos=diss.tellg();
      diss.read((char*)&v11,sizeof(v11));
      if(h==v11.n)
      {
	 diss.seekg(pos);
	 v11.count++;
	 diss.write((char*)&v11,sizeof(v11));

      }
   }
//   v11.count++;
   diss.close();
   }           */
   if(an=='t')
   {
      voter v12;
      ifstream final("CAN.DAT",ios::in|ios::binary);
      while(!final.eof())
      {
	 final.read((char*)&v12,sizeof(v12));
	 cout<<"\n";
	 v12.putdata();
	 cout<<"\nTotal Votes=\t";
	 cout<<v12.count<<"\n";
      }
      final.close();
   }
   else if(an=='r')
   {
   voter v5;
   int v;
   int vot=-1;
   int canid;
   clrscr();
   ifstream fin("CAN.DAT",ios::in|ios::binary);
   while(!fin.eof())
   {
      fin.read((char*)&v5,sizeof(v5));
      v=v5.getvotes();
      if(v>vot)
      {
	 vot=v;
	 canid=v5.n;
      }
   }
   fin.close();
   voter v13;
   ifstream fin2("CAN.DAT",ios::in|ios::binary);
   while(!fin2.eof())
   {
      fin2.read((char*)&v13,sizeof(v13));
      if(v13.n==canid)
      {
	 cout<<"THE STUDENT WITH MAXIMUM VOTES IS\n";
	 v13.putdata();
	 break;
      }
   }
   fin2.close();
   cout<<"\nTHANK YOU\n";
   }
   getch();
}

void menu(int &pos)
{
  /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;
   initgraph(&gdriver, &gmode, "C:\\turboC3\\bgi\\");

      /* read result of initialization */
   errorcode = graphresult();
   if (errorcode != grOk)  /* an error occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1); /* terminate with an error code */
   }
   setcolor(WHITE);
   line(0,45,630,45);       // draws the
   line(0,45,0,425);       // background lines
   line(0,425,630,425);
   line(630,45,630,425);
   setlinestyle(SOLID_LINE,NORM_WIDTH,1);
   setcolor(WHITE);
  //menuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuu
   int ar[5];
   ar[1]=60;
   ar[2]=160;
   ar[3]=260;
   ar[4]=360;
   rectangle(220,ar[1],400,ar[1]+40);
   outtextxy(240,75,"REGISTER VOTERS");
   rectangle(220,ar[2],400,ar[2]+40);
   outtextxy(240, 175, "REGISTER CANDIDATES");
   rectangle(220,ar[3],400,ar[3]+40);
   outtextxy(225,275,"CANDIDATE\VOTER DETAILS");
   rectangle(220,ar[4],400,ar[4]+40);
   outtextxy(300, 375, "VOTE");
   setcolor(YELLOW);
   rectangle(220,60,400,100);
   outtextxy(400,375,"Tally/Result(press g)");
   char ch=100,s;

   while(ch==100)
   {
      if(kbhit())
      {
	 s=getch();
	 if(s==80)
	 {
	    if(pos<4)
	    {
	       setcolor(WHITE);
	       rectangle(220,ar[pos],400,ar[pos]+40);
	       pos=pos+1;
	       setcolor(YELLOW);
	       rectangle(220,ar[pos],400,ar[pos]+40);
	    }
	 }
	 if(s==72)
	 {
	    if(pos>1)
	    {
	       setcolor(WHITE);
	       rectangle(220,ar[pos],400,ar[pos]+40);
	       pos=pos-1;
	       setcolor(YELLOW);
	       rectangle(220,ar[pos],400,ar[pos]+40);
	    }
	 }
	 if(s==32)
	 {
	    ch=32;
	 }
	 if(s==103)
	 {
	    char u[20],p[20];
	    password(char u,char p);
	 }
      }
   }
   closegraph();
}
void details()
 {
  /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;
   initgraph(&gdriver, &gmode, "C:\\turboC3\\bgi\\");

      /* read result of initialization */
   errorcode = graphresult();
   if (errorcode != grOk)  /* an error occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1); /* terminate with an error code */
   }



   setcolor(WHITE);
   line(0,45,630,45);       // draws the
   line(0,45,0,425);       // background lines
   line(0,425,630,425);
   line(630,45,630,425);
   setlinestyle(SOLID_LINE,NORM_WIDTH,1);
   setcolor(WHITE);

   int ar[3];
   ar[1]=100;
   ar[2]=380;
   rectangle(ar[1],200,ar[1]+150,240);
   outtextxy(120,215,"VOTER DETAILS");
   rectangle(ar[2],200,ar[2]+170,240);
   outtextxy(405,215, "CANDIDATE DETAILS");
   setcolor(YELLOW);
   rectangle(100,200,250,240);

   char ch=100,s;
   int p=1;

   while(ch==100)
   {
      if(kbhit())
      {
	 s=getch();
	 if(s==77)
	 {
	    if(p<2)
	    {
	       setcolor(WHITE);
	       rectangle(ar[p],200,ar[p]+150,240);
	       p=p+1;
	       setcolor(YELLOW);
	       rectangle(ar[p],200,ar[p]+170,240);
	    }
	 }
	 if(s==75)
	 {
	    if(p>1)
	    {
	       setcolor(WHITE);
	       rectangle(ar[p],200,ar[p]+170,240);
	       p=p-1;
	       setcolor(YELLOW);
	       rectangle(ar[p],200,ar[p]+150,240);
	    }
	 }
	 if(s==32)
	 {
	    ch=32;
	 }
      }
   }
   closegraph();
  // clrscr();

   if(p==1)
   {
      int vvv;
      voter v7;
      clrscr();
   //vote button is pressed
    /*  cout<<"PLEASE ENTER YOUR VOTER ID \n";
      cin>>vvv;
      cout<<"\n\n";         */
      cout<<"\tVOTER ID\tNAME\t\tAGE\n";
      cout<<"----------------------------------------------------\n";
     // long ya=5122;
      ifstream fi("VOTER.DAT",ios::in|ios::binary);
      while(!fi.eof())
      {
	 fi.read((char*)&v7,sizeof(v7));
	    cout<<"\t"<<v7.n<<"    \t"<<v7.name<<"    \t"<<v7.age<<"\n";
	   // break;

      }
      fi.close();
   }
   else if(p==2)
   {
      int vvvv;
      voter v8;
      clrscr();
  /*    int yo=1321;

      cout<<"PLEASE ENTER YOUR VOTER ID\n";
      cin>>vvvv;                */
      cout<<"\tVOTER ID\tNAME\t\tAGE\n";
      cout<<"----------------------------------------------------\n";
      ifstream fii("CAN.DAT",ios::in|ios::binary);
      while(!fii.eof())
      {
	 fii.read((char*)&v8,sizeof(v8));
	 if(!fii.eof())
	 {
	    cout<<"\t"<<v8.n<<"    \t"<<v8.name<<"    \t"<<v8.age<<"\n";
	 }
      }
      fii.close();
    //  clrscr();
    closegraph();
   }
}
void main()
{
   clrscr();
     /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;
   initgraph(&gdriver, &gmode, "C:\\turboC3\\bgi\\");

      /* read result of initialization */
   errorcode = graphresult();
   if (errorcode != grOk)  /* an error occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1); /* terminate with an error code */
   }


      char user[50],pass[50];
  anime();
  password(user,pass);
   int pos=1;
   menu(pos);
   char ans3='y';
   while(pos)
   {
   switch(pos)
   {
      case 1 :voterregis();
	      clrscr();
	      cout<<"DO YOU WANT TO GO BACK TO MENU SCREEN\n";
	      cin>>ans3;
	      if(ans3=='y'||ans3=='Y')
	      {
		 pos=1;
		 menu(pos);
	      }
	      else if(ans3=='n')
	      exit(0);
	      break;
      case 2 :candregis();
	      clrscr();
	      cout<<"DO YOU WANT TO GO BACK TO MENU SCREEN\n";
	      cin>>ans3;
	      if(ans3=='y'||ans3=='Y')
	      {
		 pos=1;
		 menu(pos);
	      }
	      //break;
	      else if(ans3=='n')
	      exit(0);
	      break;
      case 3 :details();
	      getch();
	      clrscr();
	      cout<<"DO YOU WANT TO GO BACK TO MENU SCREEN\n";
	      cin>>ans3;
	      if(ans3=='y'||ans3=='Y')
	      {
		 pos=1;
		 menu(pos);
	      }
	   //   break;
	      else if(ans3=='n')
	      exit(0);
	      break;
      case 4 :voting();
	      clrscr();
	      cout<<"DO YOU WANT TO GO BACK TO MENU SCREEN\n";
	      cin>>ans3;
	      if(ans3=='y'||ans3=='Y')
	      {
		 pos=1;
		 menu(pos);
	      }
	   //   break;
	      else if(ans3=='n')
	      exit(0);
	      break;
     default :break;
  }
  }
  cout<<"exited";
  getch();
}

void results()
{
   voter v5;
   int v;
   int vot=-1;
   long int canid;
   clrscr();
   fstream fin("CANDIDATE.DAT",ios::in|ios::binary);
   while(!fin.eof())
   {
      fin.read((char*)&v5,sizeof(v5));
      v=v5.getvotes();
      if(v>vot)
      {
	 vot=v;
	 canid=v5.n;
      }
   }
   fin.close();
   fstream fin2("CANDIDATE.TXT",ios::in|ios::binary);
   while(!fin2.eof())
   {
      fin2.read((char*)&v5,sizeof(v5));
      if(v5.n==canid)
      {
	 cout<<"THE STUDENT WITH MAXIMUM VOTES IS\n";
	 v5.putdata();
	 break;
      }
   }
   fin2.close();
}
/*   cout<<"\n DO YOU WANT TO SEE THE RESULT GRAPH\n";
   char cn='y';
   cin>>cn;
   if(cn=='y'||cn=='Y')
   {
      void graph();
   }        */
