#include "linkedlist.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(int argc, char *argv[]){
  Node* head = NULL;
  Node* node = create_new_node("test");
  insert(&head, node);
  print(head);
  return 0;
  
}

