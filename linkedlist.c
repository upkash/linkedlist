// linkedlist.c
//

#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Node *create_new_node(char* val){
  //Initialize new node, allocate memory, and copy string value inputted
  Node* new_node = (Node*)malloc(sizeof(struct Node));
  char* new = (char*)malloc(50);
  strcpy(new, val);
  new_node->val = new;
  //set the next pointer to null and return the new node
  new_node->next = NULL;
  return(new_node);
}

void insert(Node **list_head, Node *to_be_inserted){
	Node* last_node = *list_head;
  //set node frequency to 1, then check if its null
	
  if(to_be_inserted == NULL){
    printf("error");
    return;
  }
  
  //if the head is null then the new node is the head
	if(*list_head == NULL){
		*list_head = to_be_inserted;
		return;
	}
  //go to last node then add node there
	while(last_node->next != NULL) {
		last_node = last_node->next;
	}
	last_node->next = to_be_inserted;
	return;
}

Node* find(Node **list_head, char* val){
	Node* curr_node = *list_head;
	while(curr_node != NULL) {
    //traverse each node, if curr node is the node we are looking for, return it
		if (strcmp(curr_node->val, val) == 0) {
			return curr_node;
		}
		curr_node = curr_node->next;
	}
  //retuen null since it was not found
	return NULL;
  
}

void deleteNode(Node **list_head, char* val) {
	Node* curr_node = *list_head;
	Node* prev = (Node*)malloc(sizeof(struct Node));
  //if it is first node, delete then return
	if (strcmp(curr_node->val, val) == 0) {
		*list_head = curr_node;
		free(curr_node);
		return;
	}
  //traverse until it is that node
	while(curr_node != NULL && curr_node->val != val){
		prev = curr_node;
		curr_node = curr_node->next;	
	}
	if (curr_node == NULL){
		return;
	}
  //set previous node pointer to the delete node next node, then free 
	prev->next = curr_node->next;
	free(curr_node);	
	
}

void deleteList(Node *list_head){
	Node* curr_node = list_head;
	Node* temp = (Node*)malloc(sizeof(struct Node));
  //free the whole list 
	while(curr_node != NULL){
		temp = curr_node;
		curr_node = temp->next;
		free(temp);
	}
	free(curr_node);
}	
void printNode(Node* print){
  //prints the val member of node, prints "-" if NULL
  if(print == NULL){
    printf("-\n");
    return;
  }
  char* s = print->val;
  printf("%s\n", s);
}
void print(Node* list_head){
  //traverses the list with printNode
  Node* curr_node = list_head;
  while(curr_node != NULL){
    printNode(curr_node);
    curr_node = curr_node->next;
  }
  return;
}

int length(Node* list_head){
  //returns the length of linked list by traversing with counter
  int len = 0;
  Node* curr_node = list_head;
 
  while(curr_node != NULL){
  	curr_node = curr_node->next;
    len++;
  }
  return len;
}

void sortLex(Node **list_head){
  Node* i = *list_head;
  for(i = *list_head; i; i = i->next){
    for(Node* j = i->next; j; j = j->next){
      //sort by lex. value
      if(i->frequency == j->frequency && strcmp(i->val, j->val) > 0) {
        char temp[40];
        //swapping node value
        strcpy(temp, i->val);
        strcpy(i->val, j->val);
        strcpy(j->val, temp);
      }
      
    }
  }
}
char* getNode(Node* print){
  //string version of printNode
  if(print == NULL){
    return("-\n");
    
  }
  char* s = print->val;
  return(strcat(s, "\n"));
}

char* printWordAt(Node *list_head, int index){
  //returns a string of a node at a specific index of linked list
  int count = 0;
  Node* curr_node = list_head;
  while(count < index && curr_node != NULL){
    curr_node=curr_node->next;
    count++;
  }
  return(getNode(curr_node));
  
}