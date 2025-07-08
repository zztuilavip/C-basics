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
// special array techniques
void reverse_array(int list1[], int size){
  int left = 0 ;
  int right = size - 1;
  while (left < right){
    int temp = list1[left];
    list1[left] = list1[right];
    list1[right] = temp;
    left++;
    right--;
  }
}
bool palin(char *str){
  int left = 0;
  int right = strlen(str) -1;
  while (left < right){
    if (str[left] != str[right]){
      return false;
    }
    left++;
    right--;
  }
  return true;
}
int max_subarray(int arr[], int size, int k){
  if (k<= 0|| k>size){
    return -1;
  }
  int current_sum = 0;
  for (int i=0; i<k; i++){
    current_sum += arr[i];
  }
  int max_sum = current_sum;
  for (int i = k; i < size; i++){
    current_sum += arr[i] - arr[i-k];
    if (current_sum > max_sum){
      max_sum = current_sum;
    }
  }
  return max_sum;
}

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
  char str[] = "abca";
  reverse_array(list1, 5);
  print_array(list1, 5);
  bool check = palin(str);
  printf("\n%d", check);
  int num_array = max_subarray(list1, 5, 2);
  printf("\n%d", num_array);
}

