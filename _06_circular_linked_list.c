#include <stdio.h>
#include <stdlib.h>
typedef struct CircularNode {
  int data;
  struct CircularNode *prev;
  struct CircularNode *next;
} CircularNode;
CircularNode* create_new_circular(int data) {
  CircularNode* new_node = (CircularNode*)malloc(sizeof(CircularNode));
  if (new_node == NULL) {
    perror("Failed to allocate memory for CircularNode");
    exit(EXIT_FAILURE);
  }
  new_node->data = data;
  new_node->prev = NULL;
  new_node->next = NULL;
  return new_node;
}

CircularNode* insert_circular_beginning(CircularNode* head, int data) {
  CircularNode* new_node = create_new_circular(data);
  if (head == NULL) {
    new_node->next  = new_node;
  }
  else {
    CircularNode* tail = head;
    while (tail->next != head) {
     tail = tail->next;
    }
    new_node->next = head;
    tail->next = new_node;
  }
  return new_node;
}
CircularNode* insert_circular_end(CircularNode* head, int data) {
  CircularNode* new_node = create_new_circular(data);
  if (head == NULL) {
    new_node->next = new_node; 
    return new_node;
  }
  else {
    CircularNode* tail = head;
    while (tail->next != head) {
      tail = tail->next;
    }
    tail->next = new_node;
    new_node->next = head;
  }
  return head;
}
void traverse_circular_list(CircularNode* head) {
  CircularNode* cur = head;
  do {
    printf("%d <->", cur->data);
    cur = cur->next;
  }
  while (cur!=NULL && cur->data != head->data);
  //printf("\n");
  //do {
    //cur = head->prev;
    //printf("%d <->", cur->data);
  //}
  //while (cur!=NULL && cur->data!=head->data);
  //printf("NULL\n");
}
int main()
{
  CircularNode* head = NULL;
  head = insert_circular_beginning(head, 5);
  head = insert_circular_beginning(head, 6);
  head = insert_circular_beginning(head, 8);
  traverse_circular_list(head);
}
