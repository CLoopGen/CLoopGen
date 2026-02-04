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
    for (i = 0; i < 20; i += 2) {
        zero[i] = work[10 + i];
        data[i] = sblock_data[i] - zero[i];
        if (i + 1 < 20) {
            zero[i+1] = work[11 + i];
            data[i+1] = sblock_data[i+1] - zero[i+1];
        }
    }
}
