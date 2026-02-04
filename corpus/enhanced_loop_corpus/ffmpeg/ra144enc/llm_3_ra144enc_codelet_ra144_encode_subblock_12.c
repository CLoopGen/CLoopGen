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
    // Variant 2: Reverse consecutive memory access pattern (backward traversal)
    for (i = 39; i >= 0; i--) {
        zero[i] = work[10 + i];
        data[i] = sblock_data[i] - zero[i];
    }
}
