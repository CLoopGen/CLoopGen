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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < m; i++) {
    BLASLONG diff = ii - jj;
    int process_small = (ii >= jj) && (diff < 2);
    int process_large = diff >= 2;

    if (process_large) {
        *(b + 0) = *(a1 + 0);
        *(b + 1) = *(a2 + 0);
    }

    if (process_small) {
        for (k = 0; k < diff; k++) {
            *(b + k) = *(a1 + k * lda);
        }
        *(b + diff) = (1.F / (*(a1 + diff * lda)));
    }

    a1++;
    a2++;
    b += 2;
    ii++;
}
}
