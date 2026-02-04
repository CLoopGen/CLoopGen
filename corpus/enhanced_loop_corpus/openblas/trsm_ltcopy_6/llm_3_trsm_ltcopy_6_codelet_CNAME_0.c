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
BLASLONG stride = lda - 4;
for (i = 0; i < m; i++) {
    float temp_b[4];
    float temp_a[4];

    temp_a[0] = *(a1 + 0 * stride);
    temp_a[1] = *(a1 + 1 * stride);
    temp_a[2] = *(a1 + 2 * stride);
    temp_a[3] = *(a1 + 3 * stride);

    if ((ii >= jj) && (ii - jj < 4)) {
        BLASLONG diag_offset = ii - jj;
        temp_b[diag_offset] = (1.F / temp_a[diag_offset]);
        for (k = diag_offset + 1; k < 4; k++) {
            temp_b[k] = temp_a[k];
        }
        for (k = 0; k < diag_offset; k++) {
            temp_b[k] = temp_a[k];
        }
    } else if (ii - jj < 0) {
        temp_b[0] = temp_a[0];
        temp_b[1] = temp_a[1];
        temp_b[2] = temp_a[2];
        temp_b[3] = temp_a[3];
    }

    *(b + 0) = temp_b[0];
    *(b + 1) = temp_b[1];
    *(b + 2) = temp_b[2];
    *(b + 3) = temp_b[3];

    b += 4;
    a1 += lda;
    ii++;
}
}
