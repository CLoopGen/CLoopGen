#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG m;
extern BLASLONG lda;
extern float *b;
extern BLASLONG i;
extern BLASLONG ii;
extern BLASLONG jj;
extern float *a1;
extern BLASLONG k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < m * 2; i += 2) {
    BLASLONG offset1 = ii - jj;
    BLASLONG offset2 = ii + 1 - jj;

    // First iteration logic unrolled
    if ((ii >= jj) && (offset1 < 4)) {
        *(b + offset1) = (1.F / (*(a1 + offset1)));
        for (BLASLONG k = offset1 + 1; k < 4; k++) {
            *(b + k) = *(a1 + k);
        }
    } else if (offset1 < 0) {
        *(b + 0) = *(a1 + 0);
        *(b + 1) = *(a1 + 1);
        *(b + 2) = *(a1 + 2);
        *(b + 3) = *(a1 + 3);
    }

    b += 4;
    a1 += lda;
    ii++;

    // Second iteration (simulated unroll)
    if (i + 1 < m) {
        if ((ii >= jj) && (offset2 < 4)) {
            *(b + offset2) = (1.F / (*(a1 + offset2)));
            for (BLASLONG k = offset2 + 1; k < 4; k++) {
                *(b + k) = *(a1 + k);
            }
        } else if (offset2 < 0) {
            *(b + 0) = *(a1 + 0);
            *(b + 1) = *(a1 + 1);
            *(b + 2) = *(a1 + 2);
            *(b + 3) = *(a1 + 3);
        }
        b += 4;
        a1 += lda;
        ii++;
    }
}
}
