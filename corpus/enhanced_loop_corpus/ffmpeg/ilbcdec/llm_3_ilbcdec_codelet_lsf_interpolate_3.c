#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *out;
extern int16_t *in1;
extern int16_t *in2;
extern int16_t coef;
extern int size;
extern int invcoef;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated via pointer arithmetic)
    int16_t *idx = (int16_t*)malloc(size * sizeof(int16_t));
    if (!idx) return; // Handle allocation failure
    for (int j = 0; j < size; j++) {
        idx[j] = j; // Identity mapping for indirect access
    }
    for (i = 0; i < size; i++) {
        int index = idx[i]; // Use indirect index
        out[index] = (coef * in1[index] + invcoef * in2[index] + 8192) >> 14;
    }
    free(idx);
}
