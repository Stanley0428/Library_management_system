#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>

#define N  10
#define book_list 1
#define search_book 2
#define borrow_book 3
#define return_book 4
#define borrow_list 5
#define book_add 6
#define book_remove 7
#define exit 8

void book_return();
void _borrow_list();
void print_list();
void search();
void borrow();
void add_book();
void remove_book();
void choice();
void menu();
//void Search_Page();
int b=0xB2;
char b00k_list[N][10] = {"Math","English","Chinese","Science","PE","physics",""}; 
char current_list[N][10] = {"Math","English","Chinese","Science","PE","physics",""}; 
int mode;

int main() 
{
    while(1)
    {
		menu();
		choice();
		if (mode == 8)
			break;
	}
	time_t t;  
    time(&t);
    printf("\nThis program has been writeen at (date and time): %s", ctime(&t));
	return 0;
}

void menu()
{
	system("cls");
	for(int a=0;a<16;a++)
	{
		printf("%c ",b);	
	}
	printf("%c\n",b);
	printf("%c\t\tMENU    \t%c\n",b,b);
	for(int a=1; a<16; a++)
	{
		printf("%c",b);
		switch(a) 
		{
			case book_list:
				printf(" 1.the book list!");
				break;
			case search_book:
				printf(" 2.search the book!");
				break;
			case borrow_book:
				printf(" 3.borrow the book!");
				break;
			case return_book:
				printf(" 4.return your book!");
				break;
			case borrow_list:
				printf(" 5.borrowed list!");
				break;
			case book_add:
				printf(" 6.add the book!");
				break;
			case book_remove:
				printf(" 7.remove the book!");
				break;
			case exit:
				printf(" 8.LOG OUT!      ");
				break;	
		}
		if(a<=8)
		{
			printf("\t\t%c\n",b);
		}
		else
		{	
			printf("\t\t\t        %c",b);
			printf("\n");
		}
	}
	for(int a=0;a<17;a++)//the bottom block of the menu 
	{
		printf("%c ",b);	
	}
	printf(" \n");
	printf("please choose the mode!!");
	scanf("%d",&mode);
}

void print_list()
{
	system("cls");
	int a;
	for(int a=0;a<30;a++)
	{
		printf("%c ",b);	
	}
	printf("\n");
	for(a=0;a<N;a++)
	{
		printf("%s ",current_list[a]);
	}
	printf("\n");
	printf("Press anything to menu...");
	getch();	
}

void search()
{
	int a;
	int cnt = 0;
	char find_book[10];
	system("cls");
	for(int a=0;a<30;a++)
	{
		printf("%c ",b);	
	}
	printf("\n");
	printf("enter the book to find:");
	scanf("%s",&find_book);
	for(a=0;a<N+1;a++)
	{
		cnt++;
		if(strcmp(find_book,current_list[a]) == 0)
		{
			printf("We got your book\n");
			break;
		}
		else if(cnt>10)
        {
        	
			printf("we don't got the book you're looking for\n");
			break;
		}
	}
//	system("pause");
	printf("Press anything to menu...");
	getch();
}

void borrow()
{
	system("cls");
	for(int a=0;a<30;a++)
	{
		printf("%c ",b);	
	}
	printf("\n");
	int a;
	int cnt1;
	char book_borrow[10];
	for(a=0;a<N;a++)
	{
		printf("%s ",current_list[a]);
	}
	printf("\n");
	printf("enter the book to borrow:");
	scanf("%s",&book_borrow);
	for(cnt1=0;cnt1<N+1;cnt1++)
	{
		if(strcmp(book_borrow,current_list[cnt1]) == 0)
		{
			current_list[cnt1][0] = '\0';
			break;
		}
		else if(cnt1 == N)
		{
			printf("we don't have this book!");
			getch();
			menu();
		}
	}
	for(a=0;a<N;a++)
	{
		printf("%s ",current_list[a]);
	}
	printf("\n");
	printf("Press anything to menu...");
	getch();	
}

void book_return()
{
	system("cls");
	for(int a=0;a<30;a++)
	{
		printf("%c ",b);	
	}
	printf("\n");
	int cnt2;
	int a;
	int jump = 0;
	char b00k_return[10];
	printf("enter the book to return:");
	scanf("%s",&b00k_return);
	for(a=0;a<N+1;a++)
	{
		if(strcmp(b00k_return,b00k_list[a]) == 0)
		{
			strcpy(current_list[a],b00k_list[a]);
			printf("the book have been returned!");
		}
		else if(jump == N)
		{
			printf("you have not borrowed the book!");
		}
		jump++;
	}
	printf("\n");
	printf("Press anything to menu...");
	getch();		
}

void choice()
{
	switch(mode)
	{
		case book_list:
			print_list();
			break;
		case search_book:
			search();
			break;
		case borrow_book:
			borrow();
			break;
		case return_book:
			book_return();
			break;
		case borrow_list:
			_borrow_list();
			break;
		case book_add:
			add_book();
			break;
		case book_remove:
			remove_book();
			break;
		case exit:
			break;
		default:
			printf("please enter the following number:");
			getch();
	}
}

void add_book()
{
	int c;
	system("cls");
	for(int a=0;a<30;a++)
	{
		printf("%c ",b);	
	}
	printf("\n");
	for(c=0;c<N+1;c++)		
	{
		printf("%s ",current_list[c]);
	}
	printf("\n");
	printf("enter the book to add in:");
	scanf("%s",current_list[6]);
	strcpy(b00k_list[6],current_list[6]);//current_list[6] copy to b00k_list[6]
	printf("the book have been added!\n");
	printf("Press anything to menu...");
	getch();
}

void remove_book()
{
	int cnt2;
	char book_del[10];
	system("cls");
	for(int a=0;a<16;a++)
	{
		printf("%c ",b);	
	}
	printf("\n");
	printf("enter the book to remove it:");
	scanf("%s",&book_del);
	for(cnt2=0;cnt2<N+1;cnt2++)
	{
		if(strcmp(book_del,current_list[cnt2]) == 0)
		{
			current_list[cnt2][0] = '\0';	
			b00k_list[cnt2][0] = '\0';	
		}
		else if(cnt2 == N)
		{
			printf("we don't have this book!\n");
		}
	}
	printf("Press anything to menu...");
	getch();
}
void _borrow_list()
{
	int cnt3,cnt4;
	for(cnt3=0;cnt3<N+1;cnt3++)
	{
		if(strcmp(b00k_list[cnt3],current_list[cnt3]) > 0)
		{
			printf("%s ",b00k_list[cnt3]);
		}
	}
	printf("\n");
	printf("Press anything to menu...");
	getch();
}


/*
int main()
{
	int b,c,d,e,f,g,temp;
	char a;
	printf("enter the character!");
	scanf("%c",&a);
	printf("enter the tier of pryramid!");
	scanf("%d",&b);

	for(c=1;c<=b;c++)
	{
		for(d=c;d<=b-1;d++)
		{
			printf(" ");
		}
		for(e=1;e<=2*c-1;e++)
		{
			printf("%c",a);
		}
		printf("\n");
	}

	for(c=b;c>0;c--)
	{
		for(d=1;d<=b-c;d++)
		{
			printf(" ");
		}
		for(temp=1;temp<=2*c-1;temp++)
		{
			printf("%c",a);
		}
		printf("\n");
	}
}
*/
