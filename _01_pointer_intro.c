#include <stdio.h>

int main() {
    int myvar = 10;
    int *pointertovar;
    pointertovar = &myvar;

printf("%p\n", (void*)&myvar); // In địa chỉ của biến
printf("%p\n", (void*)pointertovar); // In địa chỉ mà con trỏ đang giữ
printf("%d\n", *pointertovar); // In giá trị tại địa chỉ đó
*pointertovar = 17;
printf("%d\n", *pointertovar);
    return 0;
}
