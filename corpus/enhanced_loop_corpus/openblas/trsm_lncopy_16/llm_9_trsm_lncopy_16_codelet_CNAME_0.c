#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG m;
extern BLASLONG lda;
extern float *b;
extern BLASLONG i;
extern BLASLONG ii;
extern BLASLONG jj;
extern BLASLONG k;
extern float *a1;
extern float *a2;
extern float *a3;
extern float *a4;
extern float *a5;
extern float *a6;
extern float *a7;
extern float *a8;
extern float *a9;
extern float *a10;
extern float *a11;
extern float *a12;
extern float *a13;
extern float *a14;
extern float *a15;
extern float *a16;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < m; i += 2) {
    BLASLONG limit = (ii - jj < 16) ? ii - jj + 1 : 0;
    if ((ii >= jj) && (limit > 0)) {
        for (k = 0; k < limit; k++) {
            float val = *(a1 + k * lda);
            if (k == ii - jj) {
                val = 1.F / val;
            }
            *(b + k) = val;
        }
    }
    if (ii - jj >= 16) {
        float *a_ptrs[] = {a1, a2, a3, a4, a5, a6, a7, a8, 
                           a9, a10, a11, a12, a13, a14, a15, a16};
        for (k = 0; k < 16; k++) {
            *(b + k) = *(a_ptrs[k] + 0);
        }
    }
    a1 += 2;
    a2 += 2;
    a3 += 2;
    a4 += 2;
    a5 += 2;
    a6 += 2;
    a7 += 2;
    a8 += 2;
    a9 += 2;
    a10 += 2;
    a11 += 2;
    a12 += 2;
    a13 += 2;
    a14 += 2;
    a15 += 2;
    a16 += 2;
    b += 32;
    ii += 2;
    if (i + 1 >= m) break;

    // Second iteration of unrolled loop
    limit = (ii >= jj && ii - jj < 16) ? ii - jj + 1 : 0;
    if (limit > 0) {
        for (k = 0; k < limit; k++) {
            float val = *(a1 + k * lda);
            if (k == ii - jj) {
                val = 1.F / val;
            }
            *(b + k) = val;
        }
    }
    if (ii - jj >= 16) {
        float *a_ptrs[] = {a1, a2, a3, a4, a5, a6, a7, a8, 
                           a9, a10, a11, a12, a13, a14, a15, a16};
        for (k = 0; k < 16; k++) {
            *(b + k) = *(a_ptrs[k] + 0);
        }
    }
    a1++;
    a2++;
    a3++;
    a4++;
    a5++;
    a6++;
    a7++;
    a8++;
    a9++;
    a10++;
    a11++;
    a12++;
    a13++;
    a14++;
    a15++;
    a16++;
    b += 16;
    ii++;
}
}
