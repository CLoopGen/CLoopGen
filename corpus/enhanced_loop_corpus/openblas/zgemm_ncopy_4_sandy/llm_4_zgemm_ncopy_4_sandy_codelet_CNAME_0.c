#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG row;
extern BLASLONG col;
extern float *src;
extern BLASLONG srcdim;
extern float *dest;
extern BLASLONG i;
extern BLASLONG j;
extern BLASLONG ii;
extern float *src0;
extern float *src1;
extern float *src2;
extern float *src3;
extern float *dest0;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < col / 4; j += 1) {
    // Use array-of-pointers style access with strided offsets to simulate indirect memory access
    float *src_ptrs[4];
    src_ptrs[0] = src;
    src_ptrs[1] = src + 2 * srcdim;
    src_ptrs[2] = src + 4 * srcdim;
    src_ptrs[3] = src + 6 * srcdim;
    src = src_ptrs[3] + 2 * srcdim;

    dest0 = dest;
    ii = (row << 3);
    dest = dest + ii;

    for (i = 0; i < row / 4; i += 1) {
        // Access through pointer array with fixed stride pattern
        // Each source pointer contributes 8 elements in two groups of 4
        for (BLASLONG k = 0; k < 4; k++) {
            BLASLONG base = k * 8;
            BLASLONG offset = i * 8;  // Stride across iterations
            dest0[base + 0] = src_ptrs[k][offset + 0];
            dest0[base + 1] = src_ptrs[k][offset + 1];
            dest0[base + 2] = src_ptrs[k][offset + 2];
            dest0[base + 3] = src_ptrs[k][offset + 3];
            dest0[base + 4] = src_ptrs[k][offset + 4];
            dest0[base + 5] = src_ptrs[k][offset + 5];
            dest0[base + 6] = src_ptrs[k][offset + 6];
            dest0[base + 7] = src_ptrs[k][offset + 7];
        }

        // Update each source pointer by 8 elements
        for (BLASLONG k = 0; k < 4; k++) {
            src_ptrs[k] += 8;
        }
        dest0 += 32;
    }

    if (row & 2) {
        for (BLASLONG k = 0; k < 4; k++) {
            BLASLONG base = k * 4;
            dest0[base + 0] = src_ptrs[k][0];
            dest0[base + 1] = src_ptrs[k][1];
            dest0[base + 2] = src_ptrs[k][2];
            dest0[base + 3] = src_ptrs[k][3];
        }
        for (BLASLONG k = 0; k < 4; k++) {
            src_ptrs[k] += 4;
        }
        dest0 += 16;
    }

    if (row & 1) {
        for (BLASLONG k = 0; k < 4; k++) {
            BLASLONG base = k * 2;
            dest0[base + 0] = src_ptrs[k][0];
            dest0[base + 1] = src_ptrs[k][1];
        }
        for (BLASLONG k = 0; k < 4; k++) {
            src_ptrs[k] += 2;
        }
        dest0 += 8;
    }
}
}
