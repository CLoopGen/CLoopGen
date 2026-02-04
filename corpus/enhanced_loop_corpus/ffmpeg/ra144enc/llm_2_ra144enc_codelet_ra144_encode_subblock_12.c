#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t *sblock_data;
extern float data[40];
extern float work[50];
extern float zero[40];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, processing even indices first then odd
    for (i = 0; i < 40; i += 2) {
        zero[i] = work[10 + i];
        data[i] = sblock_data[i] - zero[i];
    }
    for (i = 1; i < 40; i += 2) {
        zero[i] = work[10 + i];
        data[i] = sblock_data[i] - zero[i];
    }
}
