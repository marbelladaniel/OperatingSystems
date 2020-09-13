// list/list.c
// 
// Implementation for linked list.
//
// <Author>

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

list_t *list_alloc(){
  list_t *new_list = (list_t *)malloc(sizeof(list_t));
  new_list -> head = (node_t *)malloc(sizeof(node_t));
  new_list -> head = NULL; 
  //new_list -> head -> value = value; 
  //printf("Allocation works! We added the number: %d\n", value);
  return new_list;
}

void list_free(list_t *node_list) {
//   node_t *free_node = node_list -> head;
//   while (free_node){
//     node_t *temp = free_node; 
//     free_node = temp -> next; 
    free(node_list);
    printf("The list is free!\n"); 
}

void list_print(list_t *l) {
  node_t *current = l -> head;
  if(current == NULL){
    printf("The list is empty.\n"); 
  }
  while(current != NULL){
    printf("[%d]\n", current -> value);
    current = current -> next;
  } 
}

int list_length(list_t *l) { 
  int i = 0;
  node_t *temp = l -> head; 
  while(temp != NULL){
    i++;
    temp = temp -> next; 
  }
  printf("The length of the list now is: %d\n", i);
  return i; 
}


void list_add_to_back(list_t *l, elem value) {
  node_t* new_node = (node_t*)malloc(sizeof(node_t)); 
  node_t* temp = l -> head;  
  new_node -> value = value; 
  new_node ->next = NULL;
  if(l->head == NULL){
    l -> head = new_node; 
    return; 
  }
  while(temp-> next != NULL){
    temp = temp->next;
  }
  temp -> next = new_node;
  //int test_case = temp -> next -> value; 
  printf("Add to back works. Added the number: %d\n", value); 
}




void list_add_to_front(list_t *l, elem value) {
  node_t* new_node = (node_t*)malloc(sizeof(node_t)); 
  new_node -> value = value;
  new_node -> next = l -> head;
  l -> head = new_node; 
  printf("Add to front works. Added the number: %d\n", value); 
}

void list_add_at_index(list_t *l, elem num, int index) { // what do you do if user enters index that doesn't exist?
  if(!l){
  printf("Unable to insert data at given position.\n"); 
  return; 
  }
  node_t* new_node = (node_t*)malloc(sizeof(node_t));
  node_t* temp = l -> head; 
  new_node -> value = num;  
  int count = 0;

  while(temp -> next != NULL){
    if(count != index){
      temp = temp -> next;  
      count ++; 
    }
  }
  new_node -> next = temp; 
  temp = new_node; 
  printf("%d was inserted at position %d.\n", num, index); 
 
}
  

elem list_remove_from_back(list_t *l) { 
  node_t* node_remove = l -> head, *secondToLast; 
  int node_val = node_remove -> value; 
  if(node_remove == NULL){ 
    printf("List is already empty.\n");
    return node_val; 
  }
  while(node_remove -> next !=NULL){
    secondToLast = node_remove; 
    node_remove = node_remove -> next; 
  }  
    secondToLast -> next = node_remove -> next; 
   
    free(node_remove); 
    printf("Successfully removed last node of list!\n"); 
    return node_val;
}


elem list_remove_from_front(list_t *l) { 
  node_t* node_remove = l -> head; 
  int node_val = node_remove -> value; 
  
  if(node_remove == NULL){ 
  printf("List is already empty.\n");
  return node_val; 
  }
  node_remove = l-> head; 
  l -> head  = l -> head -> next; 
  printf("Successfully removed first node of list!\n");
  free(node_remove); 
  return node_val; 
}

bool list_is_in(list_t *l, elem check) {
  node_t* temp = (node_t*)malloc(sizeof(node_t));
  temp = l -> head;
  int check_value = check; 
   
  while(temp !=NULL && temp-> value != check){
    temp = temp-> next; 
    if(temp -> value == check){
       printf("Number %d is in the list.\n", temp-> value);
      return true; 
    }else if(temp -> value != check && temp != NULL ){
      printf("Number [%d] is NOT in the list.\n", check_value); 
      return false; 
    }else if(l -> head == NULL){
      printf("The list is empty.\n");
      return false; 
    }
  }  
}
  
 elem list_remove_at_index(list_t *l, int index) { 
  if(!l){
  printf("Unable to remove data at given position.\n"); 
  return; 
  }
  //node_t* new_node = (node_t*)malloc(sizeof(node_t));
  node_t* temp = l -> head; 
  //new_node -> value = num;  
  int count = 0;

  while(temp -> next != NULL && count != index - 1){
      temp = temp -> next;  
      count ++; 
    }
  node_t* remove_node = temp -> next; 
  int check = temp -> next -> value; 
  temp -> next = temp -> next -> next;
  printf("The value %d was removed at position %d.\n", check , index);
  free(remove_node);  
  return check; 
}


elem list_get_elem_at(list_t *l, int index) { 
  node_t* temp = (node_t*)malloc(sizeof(node_t));
  int i = 0; 
  temp = l -> head; 
  
  while(temp != NULL && i != index){
    temp = temp -> next; 
    i++;
  }
  printf("The value at index %d is %d.\n ", index, temp -> value);

  return index; 
}


int list_get_index_of(list_t *l, elem check) { 
  node_t* temp = (node_t*)malloc(sizeof(node_t));
  int i = 0; 
  temp = l -> head; 
  while(temp!= NULL && temp -> value != check){
    temp = temp -> next; 
    i++; 
  }
  if(temp-> value == check){
    printf("The number %d is in index %d.\n", check, i);
    return 1; 
  }
  else if(temp-> value != check){
    printf("The number %d is NOT in the list.", check); 
    return; 
  }
}