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
extern float *dest1;
extern float *dest2;
extern float *dest4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < row / 4; j += 1) {
    src0 = src;
    src1 = src0 + 2 * srcdim;
    src2 = src1 + 2 * srcdim;
    src3 = src2 + 2 * srcdim;
    src = src3 + 2 * srcdim;
    dest0 = dest;
    ii = (4 << 4);
    dest = dest + ii;
    for (i = 0; i < col / 8; i += 1) {
        // Introduce artificial loop-carried dependency via accumulation in dest
        for (int offset = 0; offset < 64; offset++) {
            dest0[offset] += src0[offset % 16];  // RAW: dest0 depends on prior value and src0
        }
        for (int offset = 0; offset < 64; offset++) {
            dest0[offset] += src1[offset % 16];
        }
        for (int offset = 0; offset < 64; offset++) {
            dest0[offset] += src2[offset % 16];
        }
        for (int offset = 0; offset < 64; offset++) {
            dest0[offset] += src3[offset % 16];
        }
        // Update pointers with stride
        src0 += 16;
        src1 += 16;
        src2 += 16;
        src3 += 16;
        ii = (row << 4);
        dest0 = dest0 + ii;
    }
    if (col & 4) {
        for (int k = 0; k < 32; k++) {
            dest4[k] += (k < 8) ? src0[k] : 
                       (k < 16) ? src1[k - 8] :
                       (k < 24) ? src2[k - 16] : src3[k - 24];
        }
        src0 += 8;
        src1 += 8;
        src2 += 8;
        src3 += 8;
        dest4 += 32;
    }
    if (col & 2) {
        for (int k = 0; k < 16; k++) {
            dest2[k] += (k < 4) ? src0[k] :
                       (k < 8) ? src1[k - 4] :
                       (k < 12) ? src2[k - 8] : src3[k - 12];
        }
        src0 += 4;
        src1 += 4;
        src2 += 4;
        src3 += 4;
        dest2 += 16;
    }
    if (col & 1) {
        for (int k = 0; k < 8; k++) {
            dest1[k] += (k < 2) ? src0[k] :
                       (k < 4) ? src1[k - 2] :
                       (k < 6) ? src2[k - 4] : src3[k - 6];
        }
        src0 += 2;
        src1 += 2;
        src2 += 2;
        src3 += 2;
        dest1 += 8;
    }
}
}
