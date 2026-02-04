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
for (i = 0; i < m; i++) {
    BLASLONG diff = ii - jj;
    if (diff >= 16) {
        *(b + 0) = *(a1 + 0);
        *(b + 1) = *(a2 + 0);
        *(b + 2) = *(a3 + 0);
        *(b + 3) = *(a4 + 0);
        *(b + 4) = *(a5 + 0);
        *(b + 5) = *(a6 + 0);
        *(b + 6) = *(a7 + 0);
        *(b + 7) = *(a8 + 0);
        *(b + 8) = *(a9 + 0);
        *(b + 9) = *(a10 + 0);
        *(b + 10) = *(a11 + 0);
        *(b + 11) = *(a12 + 0);
        *(b + 12) = *(a13 + 0);
        *(b + 13) = *(a14 + 0);
        *(b + 14) = *(a15 + 0);
        *(b + 15) = *(a16 + 0);
    } else if ((ii >= jj) && (diff < 16)) {
        for (k = 0; k < diff; k++) {
            *(b + k) = *(a1 + k * lda);
        }
        *(b + diff) = (1.F / (*(a1 + diff * lda)));
    }
    a1++; a2++; a3++; a4++; a5++; a6++; a7++; a8++;
    a9++; a10++; a11++; a12++; a13++; a14++; a15++; a16++;
    b += 16;
    ii++;
}
}
