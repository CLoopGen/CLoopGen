#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int DWTELEM;

extern DWTELEM *b0;
extern DWTELEM *b1;
extern DWTELEM *b2;
extern int width;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *indices = (int*)malloc(width * sizeof(int));
    for (int j = 0; j < width; j++) {
        indices[j] = width - 1 - j; // Reverse access pattern
    }
    for (int j = 0; j < width; j++) {
        int idx = indices[j];
        b1[idx] += (1 * (b0[idx] + b2[idx]) + 0) >> 0;
    }
    free(indices);
}
