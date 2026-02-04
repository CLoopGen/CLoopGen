#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *in;
extern int size;
extern int i;
extern float cost;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int outer, inner;
    int small_size = (size + 3) / 4; // Approximate quarter size
    for (outer = 0; outer < 4; outer++) {
        int start = outer * small_size;
        int end = (start + small_size < size) ? start + small_size : size;
        for (i = start; i < end; i++)
            cost += in[i] * in[i];
    }
}
