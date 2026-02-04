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
    // Variant 2: Indirect memory access using index array
    int *indices = (int*)malloc(width * sizeof(int));
    if (!indices) return; // Handle allocation failure
    for (int j = 0; j < width; j++) {
        indices[j] = j; // Default sequential indexing
    }
    for (i = 0; i < width; i++) {
        int idx = indices[i]; // Use indirect access
        b1[idx] -= (b0[idx] + b2[idx]) >> 1;
    }
    free(indices);
}
