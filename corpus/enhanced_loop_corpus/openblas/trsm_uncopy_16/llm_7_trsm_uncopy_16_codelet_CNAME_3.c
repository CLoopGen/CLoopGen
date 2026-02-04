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
BLASLONG prev_ii = ii;
for (i = 0; i < m; i++) {
    BLASLONG current_offset = prev_ii - jj;
    if ((prev_ii >= jj) && (current_offset < 2)) {
        *(b + current_offset) = (1.F / (*(a1 + current_offset * lda)));
        for (k = current_offset + 1; k < 2; k++) {
            *(b + k) = *(a1 + k * lda);
        }
    }
    if (current_offset < 0) {
        *(b + 0) = *(a1 + 0);
        *(b + 1) = *(a2 + 0);
    }
    a1++;
    a2++;
    b += 2;
    prev_ii++;
}
ii = prev_ii;
}
