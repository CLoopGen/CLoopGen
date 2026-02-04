#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t **samples;
extern int16_t **matrix;
extern int in_ch;
extern int len;
extern int i;
extern int j;
extern int v0;
extern int v1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive Memory Access via Pointer Promotion
    // Reorganize inner loop to use direct pointer arithmetic for consecutive access,
    // improving cache locality by dereferencing pointers that step linearly.

    for (i = 0; i < len; i++) {
        v0 = v1 = 0;
        const int16_t* s_ptr = &samples[0][i];  // Base pointer for samples[:,i]
        const int16_t* m0_ptr = matrix[0];      // Row 0 of matrix
        const int16_t* m1_ptr = matrix[1];      // Row 1 of matrix

        for (j = 0; j < in_ch; j++) {
            int16_t s_val = s_ptr[j * sizeof(int16_t*)/sizeof(int16_t)]; // Simulate strided base but consecutive j
            v0 += s_val * m0_ptr[j];
            v1 += s_val * m1_ptr[j];
        }
        samples[0][i] = (v0 + 2048) >> 12;
        samples[1][i] = (v1 + 2048) >> 12;
    }
}
