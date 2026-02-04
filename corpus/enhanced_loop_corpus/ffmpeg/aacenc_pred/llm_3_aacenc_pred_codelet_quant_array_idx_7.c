#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float val;
extern  float *arr;
extern  int num;
extern int i;
extern int _usr_index;
extern float quant_min_err;

// Variable name mappings to avoid conflicts with system symbols
#define index _usr_index



void loop(){
int *indices = (int*)malloc(num * sizeof(int));
if (!indices) return;
for (int j = 0; j < num; j++) {
    indices[j] = j;
}
for (i = 0; i < num; i++) {
    int access_idx = indices[i];
    float error = (val - arr[access_idx]) * (val - arr[access_idx]);
    if (error < quant_min_err) {
        quant_min_err = error;
        index = access_idx;
    }
}
free(indices);
}
