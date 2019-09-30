#include<stdio.h>
#include<stdlib.h>


struct node {
int value;
struct node *next;
};
typedef struct node* NODE;

NODE getnode()
{
	NODE x;

	x = (NODE)malloc(sizeof(struct node));
	if(x==NULL)
	printf("No Memory\n");
	return x;
}

NODE insert_front(NODE first, int item)
{
	NODE y;
	y = getnode();
    if (first == NULL)
    {
        y->value = item;
        y->next = NULL;
        return y;
    }
    y->value = item;  
	y->next = first;
	return y;
	
}

NODE insert_end(NODE first, int item)
{
	NODE x,temp;
	temp=first;
	x = getnode();
	x->value = item;
	x->next = NULL;
	if(first==NULL)
	return x;
	while(temp->next!=NULL)
	{
		temp = temp->next;
	}
	temp->next=x; 
	return first;
}

NODE insert_pos(NODE first,int item,int pos)
{
	NODE temp,curr,prev;
	int count = 1;
	temp = getnode();
	temp->value = item;
	temp->next = NULL;
	if(first==NULL && pos==1)
	return temp;
	if(first==NULL && pos!=1)
	printf("Invalid position\n");
	curr = first;
	prev = NULL;
	while(curr->next!=NULL && count!=pos)
	{
		prev = curr;
		curr = curr->next;
		count++;
	}
	if(count==pos)
	{
		prev->next = temp;
		temp->next = curr;
		return first;
	}
	else 
	printf("Not a valid position\n");
}

void display(NODE first)
{
	NODE temp=first;
	printf("List contains:\n");
	while(temp!=NULL)
	{
		printf("%d ",temp->value);
		temp = temp->next;
	}
}

int main()
{
	NODE first = NULL;
	int item;
	int choice = 0;
	int pos;
	while(choice != 5){
	printf("\nEnter operation: ");
	printf("\n1.Enter beginning: ");
	printf("\n2.Enter end: ");
	printf("\n3.Enter at any position: ");
	printf("\n4.Display: \n");
	printf("\n5.Exit: ");
	
	scanf("%d",&choice);
	switch(choice){
		case 1:
			printf("\nEnter item: ");
			scanf("%d",&item);
			first = insert_front(first,item);
			break;

		case 2:
			printf("\nEnter item: ");
			scanf("%d",&item);
			insert_end(first,item);
			break;
		case 3:
			printf("\nEnter item: ");
			scanf("%d",&item);
			printf("\nEnter position: ");
			scanf("%d",&pos);
			insert_pos(first,item,pos);
			break;		
        	case 4:
            		display(first);
			break;
		case 5:
			printf("Exiting program...");
            		break;
		default:
			printf("\nWrong choice");
			}
		}

return 0;
}
