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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
BLASLONG temp_a[8];
for (i = 0; i < m; i++) {
    BLASLONG offset = ii - jj;

    temp_a[0] = (BLASLONG)(*(a1 + 0));
    temp_a[1] = (BLASLONG)(*(a2 + 0));
    temp_a[2] = (BLASLONG)(*(a3 + 0));
    temp_a[3] = (BLASLONG)(*(a4 + 0));
    temp_a[4] = (BLASLONG)(*(a5 + 0));
    temp_a[5] = (BLASLONG)(*(a6 + 0));
    temp_a[6] = (BLASLONG)(*(a7 + 0));
    temp_a[7] = (BLASLONG)(*(a8 + 0));

    if ((ii >= jj) && (offset < 8)) {
        *(b + offset) = (1.F / (*(a1 + offset * lda)));
        for (k = offset + 1; k < 8; k++) {
            *(b + k) = *(a1 + k * lda);
        }
    }
    if (offset < 0) {
        for (k = 0; k < 8; k++) {
            *(b + k) = (float)temp_a[k];
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
    b += 8;
    ii++;
}
}
