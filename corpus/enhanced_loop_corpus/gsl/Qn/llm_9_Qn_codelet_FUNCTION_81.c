#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int ni;
extern int *left;
extern int *right;
extern int *weight;
extern int i;
extern int j;
extern int jh;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 2; i < ni; i += 2) {
    int left_val1 = left[i-1], right_val1 = right[i-1];
    int left_val2 = left[i], right_val2 = right[i];
    
    if (left_val1 <= right_val1) {
        weight[j] = right_val1 - left_val1 + 1;
        jh = left_val1 + weight[j] / 2;
        ++j;
    }
    if (left_val2 <= right_val2) {
        weight[j] = right_val2 - left_val2 + 1;
        jh = left_val2 + weight[j] / 2;
        ++j;
    }
}
}
