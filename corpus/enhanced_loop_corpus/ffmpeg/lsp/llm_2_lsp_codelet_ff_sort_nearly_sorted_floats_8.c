#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *vals;
extern int len;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with forward traversal using temporary array
    float *temp_vals = (float*)malloc(len * sizeof(float));
    for (int i = 0; i < len; i++) {
        temp_vals[i] = vals[i];
    }
    for (int i = 1; i < len; i++) {
        float key = temp_vals[i];
        int j = i - 1;
        while (j >= 0 && temp_vals[j] > key) {
            temp_vals[j + 1] = temp_vals[j];
            j--;
        }
        temp_vals[j + 1] = key;
    }
    for (int i = 0; i < len; i++) {
        vals[i] = temp_vals[i];
    }
    free(temp_vals);
}
