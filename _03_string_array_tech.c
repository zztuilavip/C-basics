#include <stdio.h> 
#include <string.h>
void print_array(int list1[], int size){
  for (int i = 0; i < size; i++){
    if (i == size - 1){
      printf("%d", list1[i]);
    }
    else{
      printf("%d, ", list1[i]);
    }
  }
}
int odd_counter(int list1[], int size) {
  int count = 0;
  for (int i = 0; i < size; i++){
    if (list1[i]% 2 != 0){
    count += 1;
    }
  }
  return count ;
}
int target(int list1[], int size, int target){
  for (int i = 0; i < size; i++){
    if (list1[i] == target){
      return i;
    }
  }
  return -1;
}  
void update(int list1[], int size, int index, int new){
  if (index > 0 && index < size){
    list1[index] = new;
  }
  else{
    printf("\nindex out of range");
  }
} 
int insert(int list1[], int size, int capacity, int index, int value){
  if (size < 0 || size > capacity){
    return -1;
  }
  if (index >= size || index < 0){
    return -1;
  }
  for (int i = size; i > index; i--){
    list1[i] = list1[i - 1];
  }
  list1[index] = value;
  return 0;
}
int delete(int list1[], int size, int index){
  if (index >= size || index < 0){
    return -1;
  }
  for (int i = index; i < size - 1; i++){
    list1[i] = list1[i+1];
  }
  list1[size-1] = 0;
  return 0;
}
// string techniques
void check_string(char *str)
{
  for (int i=0; str[i] != '\0'; i++){
    printf("%c%d,", str[i], i);
  
  }
}
int find_string(char *str, char target_char)
{
  for (int i=0; str[i] != '\0'; i++){
    if (str[i] == target_char){
      return i;
    }
  }  
  return -1;
}

void update_str(char *str, int index, char new_char){
  if (index < 0 || index >= strlen(str)){
    printf("Index out of range.");
  }
  else {
    str[index] = new_char;
    printf("\n");
    printf(str);
  }
}
int main() { 
  int list1[10] = {1, 3, 0, 5, 4} ;
  //int odd = odd_counter(list1, 5);
  //printf("%d", odd);
  //int tag = target(list1, 5, 5);
  //printf("\n%d", tag);
  //update(list1, 5, 1, 9);
  printf("\n");
  int res = insert(list1, 6, 10, 2, 7);
  //printf("%d", res);
  delete(list1, 6, 2);
  print_array(list1, 10);
  char str1[] = "abcde";
  check_string(str1);
  int num = find_string(str1, 'c');
  printf("\nIndex of char: %d", num);
  update_str(str1, 1, 'z');
}

