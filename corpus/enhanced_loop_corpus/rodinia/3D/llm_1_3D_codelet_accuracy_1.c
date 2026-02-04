#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *arr1;
extern float *arr2;
extern int len;
extern float err;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int outer_len = (len + 1) / 2;
    int inner_len = 2;
    for (i = 0; i < outer_len; i++) {
        for (int j = 0; j < inner_len; j++) {
            int idx = i * inner_len + j;
            if (idx < len) {
                err += (arr1[idx] - arr2[idx]) * (arr1[idx] - arr2[idx]);
            }
        }
    }
}
