#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define STACKSIZE 4

int top=-1,stack[STACKSIZE];
void push();
void pop();
void display();

void main()
{
	int ch;
	clrscr();
	while(1)
	{
		printf("\n\n1.Push\n2.Pop\n3.Display\n4.Exit");
		printf("\n\nEnter choice(1-4):");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1: push();
					break;
			case 2: pop();
					break;
			case 3: display();
					break;
			case 4: exit(0);

			default: printf("\nWrong Option");
		}

	}
	getch();
	}


void push()
{
	int val;

	if(top==STACKSIZE-1)
	{
		printf("\nStack overflow");
	}
	else
	{
		printf("\nEnter element to push:");
		scanf("%d",&val);
		top=top+1;
		stack[top]=val;
	}
}

void pop()
{
	if(top==-1)
	{
		printf("\nStack underflow");
	}
	else
	{
		printf("\n item popped:%d",stack[top]);
		top=top-1;
	}
}

void display()
{
	int i;

	if(top==-1)
	{
		printf("\nStack is empty");
	}
	else
	{
		printf("\nStack is\n");
		for(i=top;i>=0;--i)
			printf("%d\n",stack[i]);
	}
}
