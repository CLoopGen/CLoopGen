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
    // Variant 2: Indirect Memory Access using index array
    int *indices = (int*)malloc(width * sizeof(int));
    if (!indices) return; // Handle allocation failure
    for (int j = 0; j < width; j++) {
        indices[j] = j; // Direct mapping, could be randomized or reordered in practice
    }
    for (i = 0; i < width; i++) {
        int idx = indices[i]; // Simulate indirect access
        b1[idx] += (3 * (b0[idx] + b2[idx]) + 4) >> 3;
    }
    free(indices);
}
