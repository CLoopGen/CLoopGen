#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG n;
extern BLASLONG ldc;
extern BLASLONG i;
extern BLASLONG j;
extern BLASLONG chunk;
extern BLASLONG remain;
extern float *c_offset1;
extern float *c_offset;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = n; j > 0; j--) {
    c_offset1 = c_offset;
    c_offset += ldc;
    if (chunk >= 4) {
        for (i = chunk / 4; i > 0; i--) {
            *(c_offset1 + 0) = 0.F;
            *(c_offset1 + 1) = 0.F;
            *(c_offset1 + 2) = 0.F;
            *(c_offset1 + 3) = 0.F;
            *(c_offset1 + 4) = 0.F;
            *(c_offset1 + 5) = 0.F;
            *(c_offset1 + 6) = 0.F;
            *(c_offset1 + 7) = 0.F;
            *(c_offset1 + 8) = 0.F;
            *(c_offset1 + 9) = 0.F;
            *(c_offset1 + 10) = 0.F;
            *(c_offset1 + 11) = 0.F;
            *(c_offset1 + 12) = 0.F;
            *(c_offset1 + 13) = 0.F;
            *(c_offset1 + 14) = 0.F;
            *(c_offset1 + 15) = 0.F;
            *(c_offset1 + 16) = 0.F;
            *(c_offset1 + 17) = 0.F;
            *(c_offset1 + 18) = 0.F;
            *(c_offset1 + 19) = 0.F;
            *(c_offset1 + 20) = 0.F;
            *(c_offset1 + 21) = 0.F;
            *(c_offset1 + 22) = 0.F;
            *(c_offset1 + 23) = 0.F;
            *(c_offset1 + 24) = 0.F;
            *(c_offset1 + 25) = 0.F;
            *(c_offset1 + 26) = 0.F;
            *(c_offset1 + 27) = 0.F;
            *(c_offset1 + 28) = 0.F;
            *(c_offset1 + 29) = 0.F;
            *(c_offset1 + 30) = 0.F;
            *(c_offset1 + 31) = 0.F;
            c_offset1 += 32;
        }
        for (i = chunk % 4; i > 0; i--) {
            *(c_offset1 + 0) = 0.F;
            *(c_offset1 + 1) = 0.F;
            *(c_offset1 + 2) = 0.F;
            *(c_offset1 + 3) = 0.F;
            *(c_offset1 + 4) = 0.F;
            *(c_offset1 + 5) = 0.F;
            *(c_offset1 + 6) = 0.F;
            *(c_offset1 + 7) = 0.F;
            c_offset1 += 8;
        }
    } else {
        for (i = chunk; i > 0; i--) {
            *(c_offset1 + 0) = 0.F;
            *(c_offset1 + 1) = 0.F;
            *(c_offset1 + 2) = 0.F;
            *(c_offset1 + 3) = 0.F;
            *(c_offset1 + 4) = 0.F;
            *(c_offset1 + 5) = 0.F;
            *(c_offset1 + 6) = 0.F;
            *(c_offset1 + 7) = 0.F;
            c_offset1 += 8;
        }
    }
    for (i = remain; i > 0; i--) {
        *c_offset1 = 0.F;
        c_offset1++;
    }
}
}
