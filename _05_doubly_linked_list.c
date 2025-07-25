#include <stdio.h>
#include <stdlib.h>
typedef struct double_note
{
  int data;
  struct double_note *prev;
  struct double_note *next ;
} double_note;

double_note* create_double_node(int data) {
  double_note* new_node = (double_note*)malloc(sizeof(double_note));
  if (new_node == NULL){
    perror("Failed to allocate memory for new node");
    exit(EXIT_FAILURE);
  }
  new_node->data = data;
  new_node->prev = NULL;
  new_node->next = NULL;
  return new_node;
}
double_note* add_double_begin(double_note* head, int data) {
  double_note* new_node = create_double_node(data);
  if (head != NULL) {
    new_node->next = head;
    head->prev = new_node;
  }
  return new_node;
}
double_note* add_double_end(double_note* head, int data) {
  double_note* new_node = create_double_node(data);
  if (head == NULL) {
    return new_node;
  }
  double_note* cur = head;
  while (cur->next != NULL) {
    cur = cur->next;
  }
  cur->next = new_node;
  new_node->prev = cur;
  return head;
}
void traverse_double_list(double_note* head) {
  double_note* cur = head;
  double_note* tail = NULL;
  while (cur!=NULL) {
    printf("%d <->", cur->data);
    tail = cur;
    cur = cur->next;
  }
  printf("NULL\n");
  cur = tail;
  while (cur!=NULL) {
    printf("%d <->", cur->data);
    cur = cur->prev;
  }
  printf("NULL\n");
}
double_note* delete_by_value(double_note* head, int data_to_delete) {
  if (head == NULL) {
  printf("danh sach trong!\n");
  return NULL; 
}
double_note* cur = head;
  while (cur != NULL && cur->data != data_to_delete) {
  cur = cur->next;
}
  if (cur == NULL) {
  printf("Khong tim thay nut %d de xoa.\n", data_to_delete);
  return head;
}
  if (cur->prev == NULL) {
  head = cur->next;
  if (head != NULL) {
    head->prev = NULL;
  }
}
  else {
  cur->prev->next = cur->next;
  if (cur->next != NULL) {
    cur->next->prev = cur->prev;
  }
  free(cur);
  return head;
}
void free_doubly_list(double_note* head) {
  double_note* cur = head;
  double_note* next_node;
  while (cur != NULL) {
    next_node = cur->next;
    free(cur);
    cur = next_node;
  }
  printf("Da giai phong bo nho cua danh sach lien ket doi.\n");
}
}
double_note* add_middle(double_note* head, int data, int data_to_add) {
  if (head == NULL) {
    head = create_double_node(data);
    return head;
  }
  double_note* cur = head;
  while (cur!=NULL && cur->data!=data) {
    cur = cur->next;
  }
  if (cur == NULL){
    return head;
  }
  else {
     double_note* new_node = create_double_node(data_to_add);
     new_node->prev = cur;
     new_node->next = cur->next;
     cur->next = new_node;
     cur = new_node->next;
     cur->prev = (cur->prev)->next;
  }
  return head;
}

int main()
{
  double_note* doubly_list = NULL;
  doubly_list = add_double_begin(doubly_list, 5);
  doubly_list = add_double_begin(doubly_list, 6);
  doubly_list = add_double_end(doubly_list, 4);
  doubly_list = delete_by_value(doubly_list, 5);
  doubly_list = add_middle(doubly_list, 6, 9);
  traverse_double_list(doubly_list);
}
