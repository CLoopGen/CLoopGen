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
extern float *src4;
extern float *src5;
extern float *src6;
extern float *src7;
extern float *dest0;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < col / 8; j += 1) {
    // Reorganize base pointers using array of pointers to enable strided access
    float *src_ptrs[8];
    src_ptrs[0] = src;
    for (int k = 1; k < 8; k++) {
        src_ptrs[k] = src_ptrs[k-1] + 2 * srcdim;
    }
    src = src_ptrs[7] + 2 * srcdim;

    dest0 = dest;
    ii = (row << 4);
    dest = dest + ii;

    for (i = 0; i < row / 4; i += 1) {
        // Strided read with unit-stride writes: transpose block by fetching one column at a time across sources
        for (BLASLONG col_idx = 0; col_idx < 8; col_idx++) {
            dest0[col_idx]       = src_ptrs[0][col_idx];
            dest0[col_idx + 8]   = src_ptrs[1][col_idx];
            dest0[col_idx + 16]  = src_ptrs[2][col_idx];
            dest0[col_idx + 24]  = src_ptrs[3][col_idx];
            dest0[col_idx + 32]  = src_ptrs[4][col_idx];
            dest0[col_idx + 40]  = src_ptrs[5][col_idx];
            dest0[col_idx + 48]  = src_ptrs[6][col_idx];
            dest0[col_idx + 56]  = src_ptrs[7][col_idx];
        }

        // Now advance each source pointer by 8 (full horizontal jump)
        for (int k = 0; k < 8; k++) {
            src_ptrs[k] += 8;
        }
        dest0 += 64; // Move destination forward by full output tile size
    }

    if (row & 2) {
        for (BLASLONG col_idx = 0; col_idx < 4; col_idx++) {
            dest0[col_idx]       = src_ptrs[0][col_idx];
            dest0[col_idx + 8]   = src_ptrs[1][col_idx];
            dest0[col_idx + 16]  = src_ptrs[2][col_idx];
            dest0[col_idx + 24]  = src_ptrs[3][col_idx];
            dest0[col_idx + 32]  = src_ptrs[4][col_idx];
            dest0[col_idx + 40]  = src_ptrs[5][col_idx];
            dest0[col_idx + 48]  = src_ptrs[6][col_idx];
            dest0[col_idx + 56]  = src_ptrs[7][col_idx];
        }
        for (int k = 0; k < 8; k++) {
            src_ptrs[k] += 4;
        }
        dest0 += 32;
    }

    if (row & 1) {
        for (BLASLONG col_idx = 0; col_idx < 2; col_idx++) {
            dest0[col_idx]       = src_ptrs[0][col_idx];
            dest0[col_idx + 8]   = src_ptrs[1][col_idx];
            dest0[col_idx + 16]  = src_ptrs[2][col_idx];
            dest0[col_idx + 24]  = src_ptrs[3][col_idx];
            dest0[col_idx + 32]  = src_ptrs[4][col_idx];
            dest0[col_idx + 40]  = src_ptrs[5][col_idx];
            dest0[col_idx + 48]  = src_ptrs[6][col_idx];
            dest0[col_idx + 56]  = src_ptrs[7][col_idx];
        }
        for (int k = 0; k < 8; k++) {
            src_ptrs[k] += 2;
        }
        dest0 += 16;
    }
}
}
