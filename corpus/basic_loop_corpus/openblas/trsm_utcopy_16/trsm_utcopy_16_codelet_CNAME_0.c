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

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < m; i++) {
    if ((ii >= jj) && (ii - jj < 16)) {
        for (k = 0; k < ii - jj; k++) {
            *(b + k) = *(a1 + k);
        }
        *(b + ii - jj) = (1.F / (*(a1 + ii - jj)));
    }
    if (ii - jj >= 16) {
        *(b + 0) = *(a1 + 0);
        *(b + 1) = *(a1 + 1);
        *(b + 2) = *(a1 + 2);
        *(b + 3) = *(a1 + 3);
        *(b + 4) = *(a1 + 4);
        *(b + 5) = *(a1 + 5);
        *(b + 6) = *(a1 + 6);
        *(b + 7) = *(a1 + 7);
        *(b + 8) = *(a1 + 8);
        *(b + 9) = *(a1 + 9);
        *(b + 10) = *(a1 + 10);
        *(b + 11) = *(a1 + 11);
        *(b + 12) = *(a1 + 12);
        *(b + 13) = *(a1 + 13);
        *(b + 14) = *(a1 + 14);
        *(b + 15) = *(a1 + 15);
    }
    b += 16;
    a1 += lda;
    ii++;
}

}
