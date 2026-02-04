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
for (i = 0; i < m; i++) {
    BLASLONG diff = ii - jj;
    int process_small = (ii >= jj && diff < 4);
    int process_large = (diff >= 4);

    if (process_large) {
        *(b + 0) = *(a1 + 0);
        *(b + 1) = *(a2 + 0);
        *(b + 2) = *(a3 + 0);
        *(b + 3) = *(a4 + 0);
    }

    if (process_small) {
        k = 0;
        goto small_loop_start;
small_loop_iter:
        *(b + k) = *(a1 + k * lda);
        k++;
small_loop_start:
        if (k < diff) goto small_loop_iter;

        *(b + diff) = (1.F / (*(a1 + diff * lda)));
    }

    a1++;
    a2++;
    a3++;
    a4++;
    b += 4;
    ii++;
}
}
