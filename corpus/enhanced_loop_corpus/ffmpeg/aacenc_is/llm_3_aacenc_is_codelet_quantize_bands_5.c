#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *out;
extern  float *in;
extern  float *scaled;
extern int size;
extern int is_signed;
extern int maxval;
extern  float Q34;
extern  float rounding;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect array access using an index mapping array (simulated via alternating forward and reverse access)
    int *indices = (int*)malloc(size * sizeof(int));
    if (!indices) return; // Handle allocation failure

    // Create an indirect access pattern: first half forward, second half backward
    int mid = size / 2;
    for (int j = 0; j < mid; j++) {
        indices[j] = j;                   // Forward
        indices[mid + j] = size - 1 - j;  // Reverse from end
    }
    // Handle odd size
    if (size % 2) indices[size - 1] = mid;

    for (i = 0; i < size; i++) {
        int idx = indices[i];  // Use indirection
        float qc = scaled[idx] * Q34;
        int tmp = (int)((qc + rounding) > ((float)maxval) ? ((float)maxval) : (qc + rounding));
        if (is_signed && in[idx] < 0.F) {
            tmp = -tmp;
        }
        out[idx] = tmp;
    }

    free(indices);
}
