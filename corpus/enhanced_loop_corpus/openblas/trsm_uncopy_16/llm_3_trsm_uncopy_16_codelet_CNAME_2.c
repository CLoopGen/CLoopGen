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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
BLASLONG stride = lda * 4;
float *pa1 = a1, *pa2 = a2, *pa3 = a3, *pa4 = a4;
float *pb = b;

for (i = 0; i < m; i++) {
    BLASLONG diff = ii - jj;
    if ((ii >= jj) && diff < 4) {
        pb[0] = 1.F / pa1[diff * lda];
        for (k = 1; k < 4 - diff; k++) {
            pb[k] = pa1[(diff + k) * lda];
        }
    }
    if (diff < 0) {
        pb[0] = pa1[0];
        pb[1] = pa2[0];
        pb[2] = pa3[0];
        pb[3] = pa4[0];
    }
    pa1++;
    pa2++;
    pa3++;
    pa4++;
    pb += 4;
    ii++;
}
a1 = pa1; a2 = pa2; a3 = pa3; a4 = pa4; b = pb;
}
