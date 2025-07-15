#include <stdio.>
#include <stdlib.h>
typedef struct linkedlist_single{
  int data;
  struct linkedlist_single *next;
} linkedlist_single;

linkedlist_single* create_singly_node(int data) {
    linkedlist_single* newNode = (linkedlist_single*)malloc(sizeof(linkedlist_single));
    if (newNode == NULL) {
        perror("Failed to allocate memory for linkedlist_single");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
linkedlist_single* insert_singly_at_beginning(linkedlist_single* head, int data) {
    linkedlist_single* newNode = create_singly_node(data);
    newNode->next = head;
    return newNode; // Nút mới trở thành head
}
linkedlist_single* insert_singly_at_end(linkedlist_single* head, int data) {
    linkedlist_single* newNode = create_singly_node(data);
    if (head == NULL) {
        return newNode; // Nếu danh sách rỗng, nút mới là head
    }
    linkedlist_single* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}
void check_single_list(linkedlist_single* head) {
  linkedlist_single* cur = head;
  while (cur != NULL){
    printf("%d->", cur->data);
    cur = cur -> next;
  }
 printf("NULL\n");  
}

int main() {
  linkedlist_single* insert_head = NULL;
  insert_head = insert_singly_at_beginning(insert_head, 30);
  check_single_list(insert_head);
  return 0;
}
