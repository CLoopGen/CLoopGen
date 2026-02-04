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
BLASLONG stride = lda - 4;
float *temp_a = a1;
float *temp_b = b;

for (i = 0; i < m; i++) {
    if ((ii >= jj) && (ii - jj < 4)) {
        BLASLONG diag_offset = ii - jj;
        temp_b[0] = (diag_offset == 0) ? (1.F / temp_a[0]) : temp_a[0];
        temp_b[1] = (diag_offset == 1) ? (1.F / temp_a[1]) : temp_a[1];
        temp_b[2] = (diag_offset == 2) ? (1.F / temp_a[2]) : temp_a[2];
        temp_b[3] = (diag_offset == 3) ? (1.F / temp_a[3]) : temp_a[3];

        for (k = diag_offset + 1; k < 4; k++) {
            temp_b[k] = temp_a[k];
        }
    }
    if (ii - jj < 0) {
        temp_b[0] = temp_a[0];
        temp_b[1] = temp_a[1];
        temp_b[2] = temp_a[2];
        temp_b[3] = temp_a[3];
    }

    temp_b += 4;
    temp_a += lda;
    ii++;
}

b = temp_b;
a1 = temp_a;
}
