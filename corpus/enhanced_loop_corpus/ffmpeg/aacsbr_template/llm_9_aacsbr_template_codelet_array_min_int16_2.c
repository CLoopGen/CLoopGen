#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t *array;
extern int nel;
extern int i;
extern int min;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = 4;
    for (i = 1; i < nel; i += stride) {
        for (int j = 0; j < stride && (i + j) < nel; j++) {
            int16_t val = array[i + j];
            if (val < min) min = val;
        }
    }
}
