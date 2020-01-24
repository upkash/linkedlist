//linkedlist.h
//linked list header file
//

#ifndef LIST_H
#define LIST_H

#include <string.h>


typedef struct Node{
	char* val;
	int frequency;
	struct Node *next;
} Node;
Node *create_new_node(char* val);
void insert(Node **list_head, Node *to_be_inserted); //insert int into list
Node* find(Node **list_head, char* val); // find int in list return pointer to node 
void deleteNode(Node **list_head, char* val); // remove node return it if exists
void deleteList(Node *list_head); // delete whole list
void printNode(Node* print); //prints node value to stdout
void print(Node *list_head); //print string with data of list in order
int length(Node *list_head); // return length of linked list
void sortLex(Node** list_head); //sort the list lexographically
char* getNode(Node* print); //return a char* of the node's val member
char* printWordAt(Node *list_head, int index); //getNode at the index'th node of *list_head
#endif