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
float prev_val = 0.0F;
for (i = 0; i < m; i++) {
    float local_b[4];
    if ((ii >= jj) && (ii - jj < 4)) {
        local_b[0] = (1.F / (*(a1 + ii - jj))) + prev_val;
        for (k = 1; k < 4 - (ii - jj); k++) {
            local_b[k] = *(a1 + ii - jj + k);
        }
        for (k = 0; k < 4 - (ii - jj); k++) {
            *(b + k) = local_b[k];
        }
        prev_val = local_b[0];
    }
    if (ii - jj < 0) {
        *(b + 0) = *(a1 + 0) + prev_val;
        *(b + 1) = *(a1 + 1);
        *(b + 2) = *(a1 + 2);
        *(b + 3) = *(a1 + 3);
        prev_val = *(b + 0);
    }
    b += 4;
    a1 += lda;
    ii++;
}
}
