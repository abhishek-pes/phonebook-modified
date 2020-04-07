#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include<dos.h>
#include<dir.h>
#include<stdio.h>
struct person
{
    char name[50];
    char address[50];
    char father_name[50];
    char mother_name[50];
    long int mble_no;
    char sex[6];
    char mail[100];
    char citizen_no[20];

    };
void menu();
void start();
void back();
void detailview();
void addrecord();
void listrecord();
void modifyrecord();
void deleterecord();
void searchrecord();
int main()
{   
    
    system("color 02");
    start();
    return 0;
}
void back()
{
    start();
}
void start()
{
    menu();
}
void menu()
{
    system("cls");
    
 printf("\t\t**********WELCOME TO PHONEBOOK*************");

printf("\n\n\t\t\t  MENU\t\t\n\n");
printf("\t1.Add New  \n\t2.List   \n\t3.DetailView  \n\t4.Delete  \n\t5.Modify \n\t6.Search \n\t7.Exit\t");

switch(getch())
{
    case '1':addrecord();
    break;
   	case '2':listrecord();
    break;
    case '3':detailview();
    break;
    case '4':deleterecord();
    break;
    case '5':modifyrecord();
    break;
    case '6':searchrecord();
    break;
    case '7':exit(0);
    break;
    default:system("cls");
            printf("\nInvalid Choice: Enter options 1 to 6 only");
            printf("\n Enter any key");
            getch();
menu();
}
}
        void addrecord()
{
        system("cls");
        FILE *f;
        struct person p;
        f=fopen("Record1","ab+");
        fflush(stdin);
        printf("\n Enter name: ");
        gets(p.name);
        fflush(stdin);
        printf("\nEnter the address: ");
        gets(p.address);
        fflush(stdin);
        printf("\nEnter father name: ");
        gets(p.father_name);
        fflush(stdin);
        printf("\nEnter mother name: ");
        gets(p.mother_name);
        fflush(stdin);
        z:
        printf("\nEnter phone no.:");
        
        scanf("%ld",&p.mble_no);
            if(p.mble_no>100000000 && p.mble_no<10000000000)
            {
                 printf("\nEnter sex:");
        scanf(" %s",p.sex);
        printf("\nEnter e-mail:");
        scanf(" %s",p.mail);
        printf("\nEnter adhaar no:");
        scanf(" %s",p.citizen_no);
        fwrite(&p,sizeof(p),1,f);

      fflush(stdin);
        printf("\nrecord saved");
            }
                else
                {
                    printf("\nInvalid Phone No.\n Please enter a valid Phone No."); 
                    goto z;
                }
        
      

fclose(f);

    printf("\n\nEnter any key");

	 getch();
    system("cls");
    menu();
}
void listrecord()
{
    fflush(stdin);
    struct person p;
    FILE *f;
    f=fopen("Record1","rb");
if(f==NULL)
{
printf("\nfile opening error in listing :");
system("cls");
menu();
}
int no=1;
printf("\n\n\n YOUR CONTACTS ARE\n");
while(fread(&p,sizeof(p),1,f)==1)
{       printf("%d. %s\n",no,p.name);
        no++;
}
fclose(f);
printf("\n Enter any key");
 getch();
    system("cls");
menu();
}
void searchrecord()
{
    struct person p;
FILE *f;
char name[100];

f=fopen("Record1","rb");
if(f==NULL)
{
    printf("\n error in opening\a\a\a\a");
    exit(1);

}
printf("\nEnter name of person to search\n");
fflush(stdin);
gets(name);
int test = -1;
while(fread(&p,sizeof(p),1,f)==1)
{
    if(strcmp(p.name,name)==0)
    {
        test = 0;
        printf("\n\tDetail Information About %s",name);
        printf("\nName:%s\naddress:%s\nFather name:%s\nMother name:%s\nMobile no:%ld\nsex:%s\nE-mail:%s\nCitision no:%s",p.name,p.address,p.father_name,p.mother_name,p.mble_no,p.sex,p.mail,p.citizen_no);
    }
        

}
if(test == -1)
printf("\nRECORD NOT FOUND");
 fclose(f);
  printf("\n Enter any key");

	 getch();
    system("cls");
menu();
}
void deleterecord()
{
    struct person p;
    FILE *f,*ft;
	int flag;
	char name[100];
	f=fopen("Record1","rb");
	if(f==NULL)
		{

			printf("CONTACT'S DATA NOT ADDED YET.");

		}
	else
	{
		ft=fopen("temp","wb+");
		if(ft==NULL)

            printf("file opening error");
		else

        {


		printf("Enter CONTACT'S NAME:");
        fflush(stdin);
		gets(name);

		
		while(fread(&p,sizeof(p),1,f)==1)
		{
			if(strcmp(p.name,name)!=0)
				fwrite(&p,sizeof(p),1,ft);
			if(strcmp(p.name,name)==0)
                flag=1;
		}
	fclose(f);
	fclose(ft);
	if(flag!=1)
	{
		printf("NO CONACT'S RECORD TO DELETE.");
		remove("temp");
	}
		else
		{
			remove("Record1");
			rename("temp","Record1");
			printf("RECORD DELETED SUCCESSFULLY.");

		}
	}
}
 printf("\n Enter any key");

	 getch();
    system("cls");
menu();
}

void modifyrecord()
{
    int c;
    FILE *f;
    int flag=0;
    struct person p,s;
	char  name[50];
	f=fopen("Record1","rb+");
	if(f==NULL)
		{

			printf("CONTACT'S DATA NOT ADDED YET.");
			exit(1);


		}
	else
	{
	    system("cls");
		printf("\nEnter CONTACT'S NAME TO MODIFY:\n");
            fflush(stdin);
            gets(name);
            while(fread(&p,sizeof(p),1,f)==1)
            {
                if(strcmp(name,p.name)==0)
                {



                    printf("\n Enter name:");
                    gets(s.name);
                    printf("\nEnter the address:");
                    gets(s.address);
                    printf("\nEnter father name:");
                    gets(s.father_name);
                    printf("\nEnter mother name:");
                    gets(s.mother_name);
                    printf("\nEnter phone no:");
                    scanf("%ld",&s.mble_no);
                    printf("\nEnter sex:");
                    scanf(" %s",s.sex);
                    printf("\nEnter e-mail:");
                    scanf(" %s",s.mail);
                    printf("\nEnter Adhaar no.\n");
                    scanf(" %s",s.citizen_no);
                    fseek(f,-sizeof(p),SEEK_CUR);
                    fwrite(&s,sizeof(p),1,f);
                    flag=1;
                    break;
                }
                fflush(stdin);

            }
            if(flag==1)
            {printf("\n your data id modified");}
            else
            {
                    printf(" \n data is not found"); }
            fclose(f);
	}
	 printf("\n Enter any key");
	 getch();
    system("cls");
	menu();

}
void detailview()
{
struct person p;
FILE *f2;
char search;
char choice[100];
f2=fopen("Record1","rb");
int checker = -1;
printf("\nEnter name of person to view full detail\n");
fflush(stdin);
gets(choice);
while(fread(&p,sizeof(p),1,f2)==1)
{
    if(strcmp(p.name,choice)==0)
    {   checker = 1;
        printf("\n\tDetail Information About %s",choice);
        printf("\nName:%s\naddress:%s\nFather name:%s\nMother name:%s\nMobile no:%ld\nsex:%s\nE-mail:%s\nAdhaar no:%s",p.name,p.address,p.father_name,p.mother_name,p.mble_no,p.sex,p.mail,p.citizen_no);
    }
}
if(checker == -1)
{   printf("\n%d",checker);
    printf("\nenter exact name from contact list");
    printf("\n do yo want to search again(y/n): ");
    fflush(stdin);
    scanf("%c",&search);
    if(search=='y'||search=='Y')
    {
    detailview();
    }
	else
	{
    system("cls");
	menu();
    }
}
else
{
fclose(f2);
 printf("\n Enter any key");
 getch();
    system("cls");
menu();
}
}
