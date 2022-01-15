#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
}*head, *newnode, *ptr;

int count = 0, i;

void insert(int value){
	newnode = (struct node*)malloc(sizeof(struct node*));
	newnode->data = value;
	if(head==NULL){
		head = newnode;
		newnode->next = head;
	}
	else{
		ptr = head;
		while(ptr->next!=head)
			ptr = ptr->next;
		ptr->next = newnode;
		newnode->next = head;
	}
	count++;
}

void ranins(int value, int pos){
	newnode = (struct node*)malloc(sizeof(struct node*));
	newnode->data = value;
	ptr = head;
	if(pos == 0){
		newnode->next = head;
		head = newnode;
		for(i=1;i<count;i++)
			ptr = ptr->next;
		ptr->next = head;
	}
	else{
		for(i=1;i<pos;i++)
			ptr = ptr->next;
		newnode->next = ptr->next;
		ptr->next = newnode;	
	}
	count++;
}

void randel(int pos){
	struct node *temp;
	ptr = head;
	if(pos == 0){
		temp = head;
		head = ptr->next;
		for(i=1;i<count;i++)
			ptr = ptr->next;
		ptr->next = head;
	}
	else{
		for(i=1;i<pos;i++)
			ptr = ptr->next;
		temp = ptr->next;
		ptr->next = ptr->next->next;
	}
	free(temp);
	count--;
}

void display(){
//	count++;
	ptr = head;
	for(i=0;i<count;i++){
		printf("%d\t",ptr->data);
		ptr=ptr->next;
	}
}

void main(){
	int value, n;
	printf("Circular Singly Linked list\n");
	do{
		scanf("%d",&value);
		insert(value);
		printf("Continue? ");
		scanf("%d",&n);
	}while(n);
//	ranins(99,0);
	randel(2);
	display();
}