#include<stdio.h>
#include<stdlib.h>

int i, len;

struct node{
	int data;
	struct node *next;
} *head, *newnode, *ptr, *temp;

void length(){
	len = 0;
	ptr = head;
	while(ptr){
		len++;
		ptr = ptr->next;
	}
//	return len;
}

// void insert(int value){
// 	newnode = (struct node*)malloc(sizeof(struct node));
// 	newnode->data = value;
// 	if(head==NULL){
// 		head = newnode;
// 		newnode->next = NULL;
// 	}
// 	else{
// 		ptr = head;
// 		while(ptr->next!=NULL)
// 			ptr = ptr->next;
// 		ptr->next = newnode;
// 		newnode->next = NULL;
// 	}
// }

void ranins (int value, int inspos){
	newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = value;
	if(head == NULL){
		head = newnode;
		newnode->next = NULL;
	}
	else if(inspos == 0){
		newnode->next = head;
		head = newnode;
	}
	else{
		ptr = head;
		for(i=1;i<inspos;i++)
			ptr = ptr->next;
		newnode->next = ptr->next;
		ptr->next = newnode;
	}
}

void search(int value){
	int pos = 0;
	ptr = head;
	while(ptr){
		if(value == ptr->data){
			printf("Value found in %d", pos);
		}
		ptr = ptr->next;
		pos++;
	}
}

// void pop(){
// 	ptr = head;
// 	while(ptr->next->next!=NULL)
// 		ptr = ptr->next;
// 	ptr->next = NULL;
// }

void delete (int delpos){
	struct node *temp;
	ptr = head;
	if(delpos == 0) {
		temp = head;
        head = ptr->next;
	}
	else{
		for(i=1;i<delpos;i++)
			ptr = ptr->next;
		temp = ptr->next;
		ptr->next = ptr->next->next;
	}
	free(temp);
}

void sort(){
	int temp;
	struct node *index = NULL;
	ptr = head;
	while(ptr){
		index = ptr->next;
		while(index){
			if(ptr->data > index->data){
				temp = ptr->data;
				ptr->data = index->data;
				index->data = temp;
			}
			index = index->next;
		}
		ptr = ptr->next;
	}
}

void display(){
	ptr = head;
	while(ptr){
		printf("%d\t",ptr->data);
		ptr = ptr->next;
	}
}

int main(int argc, char const *argv[]){
	int value, opt, n, pos;
	printf("Singly Linked list\n");
	do{
		printf("\n1. Insert\n2. Random Insert\n3. Display\n4. Pop\n5. Search\n6. Delete\n7. Sort\n8. Exit\nYour Choice? ");
		scanf("%d",&opt);
		switch(opt){
			case 1:
				printf("Enter data ");
				scanf("%d",&value);
				length();
				ranins(value,len);
				break;
			case 2:
				printf("Enter Data & Position ");
				scanf("%d%d",&value,&pos);
				ranins(value,pos);
				break;
			case 3:
				display();
				break;
			case 4:
				length();
				delete(len-1);
				break;
			case 5:
				printf("Enter data ");
				scanf("%d",&value);
				search(value);
				break;
			case 6:
				printf("Enter Position ");
				scanf("%d",&pos);
				delete(pos);
				break;
			case 7: 
				sort();
				break;
			case 8:
				exit(0);
				break;
			default:
				continue;
		}
		printf("\nContinue?(0/1) ");
		scanf("%d",&n);
	} while (n==1);
	return 0;
}