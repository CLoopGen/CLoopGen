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
for (i = 0; i < m; i += 2) { // Double trip count step to reduce iterations
    if ((ii >= jj) && (ii - jj < 2)) {
        *(b + ii - jj) = (1.F / (*(a1 + ii - jj)));
        if (i + 1 < m) { // Process two rows if possible
            BLASLONG ii_next = ii + 1;
            if ((ii_next >= jj) && (ii_next - jj < 2)) {
                *(b + 2 + ii_next - jj) = (1.F / (*(a1 + lda + ii_next - jj)));
            }
        }
        for (k = ii - jj + 1; k < 2; k++) {
            *(b + k) = *(a1 + k);
            if (i + 1 < m) {
                *(b + 2 + k) = *(a1 + lda + k);
            }
        }
    }
    if (ii - jj < 0) {
        *(b + 0) = *(a1 + 0);
        *(b + 1) = *(a1 + 1);
        if (i + 1 < m) {
            *(b + 2) = *(a1 + lda + 0);
            *(b + 3) = *(a1 + lda + 1);
        }
    }
    b += 4;   // Advance output by two rows
    a1 += 2 * lda; // Skip two rows in input
    ii += 2;
}
}
