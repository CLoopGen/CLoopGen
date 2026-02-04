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
    int temp_weight;
    int temp_jh;
    for (i = 1; i < ni; ++i) {
        if (left[i] <= right[i]) {
            temp_weight = right[i] - left[i] + 1;
            weight[j] = temp_weight;
            temp_jh = left[i] + temp_weight / 2;
            jh = temp_jh;
            ++j;
        }
    }
}
