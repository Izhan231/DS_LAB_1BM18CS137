#include <stdio.h>
#include <stdlib.h>

#define size 5

struct node {
	int data;
	struct node *next;
};

typedef struct node * NODE;

NODE getnode() {
	NODE p;
	p = (NODE) malloc(sizeof(struct node));
	if (p != NULL) return p;
	else {
	printf("No Memory \n");
	return NULL;
	}
}

NODE insert(int ele, NODE head, int *len) {
	if (*len == size - 1) {
		printf("Overflow \n");
		return head;
	}
	NODE p, q;
	q = getnode();
	q -> data = ele;
	q -> next = NULL;
	if (head == NULL) return q;
    	p = head;
	while (p -> next != NULL) p = p -> next;
    	p -> next = q;
	printf("Inserted \n");
	return head;

}

NODE delete(NODE head, int *len) {
	NODE p = head;
	if (head == NULL) {
		printf("Empty \n");
		return head;
	}
	printf("Deleted \n");
	head = p -> next;
	free(p);
	(*len)--;
	return head;
}

void display (NODE head) {
    	NODE p;
	if (head == NULL) {
		printf("Empty List \n");
		return;
	}
	p = head;
	while (p != NULL) {
		printf("%d \n", p -> data);
		p = p -> next;
	}
}

int main() {
	int choice, len = 0, ele;
	NODE head = NULL;

	do {
		printf("1. Insert \n");
		printf("2. Delete \n");
		printf("3. Display \n");
		printf("4. Exit \n");
		printf("Enter Choice \n");
		scanf("%d", &choice);

		switch (choice) {
		    case 1: printf("Enter Element \n");
			    scanf("%d", &ele);
			    head = insert(ele, head, &len);
			    break;
		    
		    case 2: head = delete(head, &len);
			    break;
			    
		    case 3: display(head);
			    break;

		    case 4: exit(0);
			    break;
		    
		    default: printf("Invalid Choice \n");
		}

	} while (choice != 4);

	return 0;
}