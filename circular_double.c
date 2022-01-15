#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next, *prev;
}*head, *ptr, *newnode;

int count = 0, i;

void insert(int data){
	newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = data;
	if(head == NULL){
		head = newnode;
		newnode->next = head;
		newnode->prev = head;
	}
	else{
		ptr = head;
		for(i=1;i<count;i++)
			ptr = ptr->next;
		ptr->next = newnode;
		newnode->next = head;
		newnode->prev = ptr;
	}
	count++;
}

void ranins(int data, int pos){
	newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = data;
	ptr = head;
	if(pos == 0){
		newnode->next = head;
		newnode->prev = head->prev;
		head = newnode;
		for(i=1;i<count;i++)
			ptr = ptr->next;
		ptr->next = head;
	}
	else{
		for(i=1;i<pos;i++)
			ptr = ptr->next;
		newnode->next = ptr->next;
		newnode->prev = ptr;
		ptr->next->prev = newnode;
		ptr->next = newnode;
	}
	count++;
}

void randel(int pos){
	struct node *temp;
	ptr = head;
	if(pos==0){
		temp = head;
		head = ptr->next;
		for(i=1;i<count;i++)
			ptr = ptr->next;
		ptr->next = head;
		head->prev = ptr;
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
	count--;
}

void display(){
//	count++;
	ptr = head;
	for(i=0;i<count;i++){
		printf("%d\t",ptr->data);
		ptr = ptr->next;
	}
}

void main(){
	int n, data;
	printf("Double Circular Linked List\n");
	do{
		scanf("%d",&data);
		insert(data);
		printf("Continue?(0/1) ");
		scanf("%d",&n);
	}while(n);
//	ranins(99,2);
	randel(1);
	display();
}