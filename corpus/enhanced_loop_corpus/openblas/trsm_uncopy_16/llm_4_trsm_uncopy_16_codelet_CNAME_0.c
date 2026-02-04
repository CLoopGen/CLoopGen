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
    BLASLONG offset = ii - jj;
    if (offset >= 0 && offset < 16) {
        float inv = 1.F / (*(a1 + offset * lda));
        *(b + offset) = inv;
        for (k = offset + 1; k < 16; k++) {
            *(b + k) = *(a1 + k * lda);
        }
        for (k = 0; k < offset; k++) {
            switch(k) {
                case 0: *(b + 0) = *(a1 + 0); break;
                case 1: *(b + 1) = *(a2 + 0); break;
                case 2: *(b + 2) = *(a3 + 0); break;
                case 3: *(b + 3) = *(a4 + 0); break;
                case 4: *(b + 4) = *(a5 + 0); break;
                case 5: *(b + 5) = *(a6 + 0); break;
                case 6: *(b + 6) = *(a7 + 0); break;
                case 7: *(b + 7) = *(a8 + 0); break;
                case 8: *(b + 8) = *(a9 + 0); break;
                case 9: *(b + 9) = *(a10 + 0); break;
                case 10: *(b + 10) = *(a11 + 0); break;
                case 11: *(b + 11) = *(a12 + 0); break;
                case 12: *(b + 12) = *(a13 + 0); break;
                case 13: *(b + 13) = *(a14 + 0); break;
                case 14: *(b + 14) = *(a15 + 0); break;
                case 15: *(b + 15) = *(a16 + 0); break;
            }
        }
    } else if (offset < 0) {
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
    }
    a1++; a2++; a3++; a4++; a5++; a6++; a7++; a8++; a9++; a10++; a11++; a12++; a13++; a14++; a15++; a16++;
    b += 16;
    ii++;
}
}
