#include <stdlib.h>
#include <stdio.h>

int kmp_search(char A[], char P[], int len_a, int len_p);
int main(int argc, char *argv[]){
    char array[16] = "---abcxxxabcy---";
    char pat[10] = "abcxxxabcy";
    int x = kmp_search(array, pat, 16, 10);
    printf("%d??", x);
}

int kmp_search(char A[], char P[], int len_a, int len_p){
    int prefix_len_arr[10] = {0};
    int idx = 0;
    for(int i = 1; i <= len_p; i++){
        if(P[i] == P[idx]){
            idx++;
            prefix_len_arr[i] = idx;
        }
        else{
            idx = 0;
        }
    }
    //print_int_array(prefix_len_arr, 10);
    int a_idx = 0, p_idx = 0;
    while(a_idx < len_a - len_p){
        if(A[a_idx + p_idx] == P[p_idx]){
            p_idx++;
            if(p_idx == len_p){
                return a_idx;
            }
        }
        else{
            a_idx = a_idx + p_idx - prefix_len_arr[p_idx];
            p_idx = __max(prefix_len_arr[p_idx], 0);
        }
    }
    return 0;
}
