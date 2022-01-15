#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *prev, *next;
}*head, *ptr, *newnode;

void insert(int value){
	newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = value;
	if(head==NULL){
		newnode->next = NULL;
		newnode->prev = NULL;
		head = newnode;
	}
	else{
		ptr = head;
		while(ptr->next!=NULL){
			ptr = ptr->next;
		}
		ptr->next = newnode;
		newnode->prev = ptr;
		newnode->next = NULL;
	}
}

void ranins(int data,int  pos){
	newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = data;
	ptr = head;
	for(int i=1;i<pos;i++)
		ptr = ptr->next;
	newnode->next = ptr->next;
	newnode->prev = ptr;
	ptr->next->prev = newnode;
	ptr->next = newnode;
	printf("\nRandomly Inserted\n");
}

void insbeg(int data){
	newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = data;
	newnode->prev = NULL;
	newnode->next = head;
	head = newnode;
	printf("\nInserted\n");
}

void pop(){
	ptr = head;
	while(ptr->next->next!=NULL)
		ptr = ptr->next;
	ptr->next = NULL;
	printf("\nPopped\n");
}

void randel(int pos){
	ptr = head;
	struct node *temp;
	if(pos == 0){
		temp = head;
		head = ptr->next;
		head->prev = NULL;
	}
	else{
		for(int i=0;i<pos;i++){
			ptr = ptr->next;
			temp = ptr;
		}
		ptr->prev->next = ptr->next;
		ptr->next->prev = ptr->prev;
	}
	free(temp);
	printf("\nDeleted\n");
}

void display(){
	ptr = head;
	while(ptr){
		printf("%d\t",ptr->data);
		ptr = ptr->next;
	}
}

int main(){
	int data, n;
	printf("Doubly Linked list\n");
	do{
		scanf("%d",&data);
		insert(data);
		printf("Continue?(0/1) ");
		scanf("%d",&n);
	}while(n);
	display();
	// pop();
	// ranins(20,3);
	// insbeg(99);
	randel(0);
	display();
	return 0;
}