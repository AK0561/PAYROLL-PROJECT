#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
#include<string.h>
main()
   {
	int gm,gd;
	FILE	*fp,*ft;
	char	another,choice;
	float 	t,ta=0,da=0,hr=0,pf=0,basic_pay=0;
	void	draw_line();
	struct emp
	   {
		char name[40];
		int staff_no;
		float bs;
	   };

	struct emp e;

	int staffno;
	long int recsize;


	fp=fopen("emp1.txt","r+");

	 if(fp==NULL)
	    {
		fp=fopen("emp1.txt","w+");

		if(fp==NULL)
		    {
			puts("Cannot open file");
			exit(0);
		    }
	     }

	     recsize=sizeof(e);

	while(1)
	 {
	   system("cls");
	   COORD c4;
  c4.X=25;
  c4.Y=1;
  SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE), c4);
printf("P a y    R o l l    S y s t e m\n");
draw_line();

 COORD c5;
  c5.X=25;
  c5.Y=5;
  SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE), c5);
printf("M A I N  M E N U");

 COORD c6;
  c6.X=25;
  c6.Y=7;
  SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE), c6);
printf("1.  Add records");

 COORD c7;
  c7.X=25;
  c7.Y=8;
  SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE), c7);
printf("2.  List records");

 COORD c8;
  c8.X=25;
  c8.Y=9;
  SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE), c8);
printf("3.  Modify records");

 COORD c9;
  c9.X=25;
  c9.Y=10;
  SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE), c9);
printf("4.  Delete records");

 COORD c10;
  c10.X=25;
  c10.Y=11;
  SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE), c10);
printf("0.  Exit");

 COORD c11;
  c11.X=1;
  c11.Y=22;
  SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE), c11);
printf("Developed By : Arnav Aggarwal, B.Tech, Register No:RA2111032010002\n");
draw_line();

 COORD c12;
  c12.X=8;
  c12.Y=24;
  SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE), c12);
printf("SRM Institute Of Science and Technology, Chennai");

 COORD c13;
  c13.X=25;
  c13.Y=13;
  SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE), c13);
printf("Your choice : ");

fflush(stdin);
choice=getche();

switch(choice)
{
case '1' :

fseek(fp,0,SEEK_END);
another='Y';

while(another=='Y')
{
	   system("cls");
	printf("\nEnter name    : ");
	gets(e.name);
	printf("Staff Number    : ");
	scanf("%d",&e.staff_no);
	printf("Basic salary    : ");
	scanf("%f",&e.bs);
	fwrite(&e,recsize,1,fp);
	printf("\nAdd another record (Y/N) ");
	fflush(stdin);
	another=getche();
}

break;

case '2' :

rewind(fp);

while(fread(&e,recsize,1,fp)==1)
	{
	  system("cls");

	/*   Calculation	*/

	     if(e.bs>=10000)
	     {
	       ta=((e.bs*9)/100);
	       da=((e.bs*15)/100);
	       hr=((e.bs*13)/100);
	       pf=((e.bs*10)/100);
	     }
	     else
	     if(e.bs>=8000)
	     {
		ta=((e.bs*8)/100);
		da=((e.bs*13)/100);
		hr=((e.bs*11)/100);
		pf=((e.bs*10)/100);
	     }
	     else
	     if(e.bs>=6000)
	     {
		ta=((e.bs*7)/100);
		da=((e.bs*11)/100);
		hr=((e.bs*9)/100);
		pf=((e.bs*10)/100);
	     }
	     else
	     if(basic_pay>=4000)
	     {
		ta=((e.bs*6)/100);
		da=((e.bs*9)/100);
		hr=((e.bs*7)/100);
		pf=((e.bs*10)/100);
	     }
	     t=((e.bs+ta+da+hr)-pf);

	/*	end of calculation	*/

	printf("\nName         : %s",e.name);
	printf("\nStaff Number : %d",e.staff_no);
	printf("\nBasic Salary : %.2f",e.bs);
	printf("\nT.A.         : %.2f",ta);
	printf("\nD.A.         : %.2f",da);
	printf("\nH.R.         : %.2f",hr);
	printf("\nP.P.F.       : %.2f",pf);
	printf("\nNet Salary   : %.2f",t);

 getch();
	}
	break;
case '3' :
another = 'Y';
while(another=='Y')
{
	  system("cls");
	printf("\nEnter staff number : ");
	scanf("%d",&staffno);

	rewind(fp);

	while(fread(&e,recsize,1,fp)==1)
	{
		if(e.staff_no==staffno)
		{
			  system("cls");
			fflush(stdin);
			printf("\nEnter new name : ");
			gets(e.name);
			printf("Staff Number     : ");
			scanf("%d",&e.staff_no);
			printf("Basic salary     : ");
			scanf("%f",&e.bs);
			fseek(fp,-recsize,SEEK_CUR);
			fwrite(&e,recsize,1,fp);
			break;
		 }

	}
	printf("\nModify more record (Y/N) : ");
	fflush(stdin);
	another=getche();
	}

	break;

	case '4' :
	another = 'Y';
	while(another=='Y')
	{
	  system("cls");

        printf("\nEnter staff number : ");
	scanf("%d",&staffno);

	ft = fopen("TEMP.DAT","w");
	rewind(fp);

	while(fread(&e,recsize,1,fp)==1)
	{
		if(e.staff_no==staffno)
			fwrite(&e,recsize,1,ft);
	}

	fclose(fp);
	fclose(ft);

	remove("emp1.txt");
	rename("TEMP.DAT","emp1.txt");

	fp=fopen("emp1.txt","r+");

	printf("\nDelete any other [Y/N] : ");
	fflush(stdin);
	another=getche();
	}

	break;

	/*	Exit from program	*/
	case '0' :

	fclose(fp);
	  system("cls");
	exit(0);

	}
     }
  }


  void draw_line()
  {
  int i;
  for(i=0;i<=119;i++)
  printf("-");
  }
