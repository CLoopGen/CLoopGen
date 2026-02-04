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
    float temp[40];
    for (i = 0; i < 40; i++) {
        temp[i] = sblock_data[i];
        zero[i] = work[10 + i];
        data[i] = temp[i] - zero[i];
    }
}
