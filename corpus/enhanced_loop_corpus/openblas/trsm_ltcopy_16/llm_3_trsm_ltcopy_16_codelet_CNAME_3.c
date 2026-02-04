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
BLASLONG stride = lda - 2;
for (i = 0; i < m; i++) {
    float *current_a1 = a1;
    float *current_b = b;
    if ((ii >= jj) && (ii - jj < 2)) {
        BLASLONG diff = ii - jj;
        current_b[0] = (diff == 0) ? (1.F / current_a1[0]) : current_b[0];
        current_b[1] = (diff == 1) ? (1.F / current_a1[1]) :
                      (diff == 0) ? current_a1[1] : current_b[1];
    }
    if (ii - jj < 0) {
        current_b[0] = current_a1[0];
        current_b[1] = current_a1[1];
    }
    b += 2;
    a1 += stride + 2;
    ii++;
}
}
