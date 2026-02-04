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
    int *left_ptr = left + 1;
    int *right_ptr = right + 1;
    for (i = 1; i < ni; ++i, left_ptr++, right_ptr++) {
        if (*left_ptr <= *right_ptr) {
            weight[j] = *right_ptr - *left_ptr + 1;
            jh = *left_ptr + weight[j] / 2;
            ++j;
        }
    }
}
