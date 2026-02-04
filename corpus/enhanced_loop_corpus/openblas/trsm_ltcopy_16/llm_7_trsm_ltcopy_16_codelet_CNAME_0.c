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
BLASLONG temp_offsets[16];
float temp_values[16];

for (i = 0; i < m; i++) {
    BLASLONG offset = ii - jj;

    for (k = 0; k < 16; k++) {
        temp_offsets[k] = k;
        temp_values[k] = *(a1 + k);
    }

    if ((ii >= jj) && (offset < 16)) {
        *(b + 0) = 1.F / temp_values[offset];
        for (k = 1; k < 16; k++) {
            *(b + temp_offsets[k]) = temp_values[temp_offsets[k]];
        }
    } else if (offset < 0) {
        for (k = 0; k < 16; k++) {
            *(b + k) = temp_values[k];
        }
    }

    for (k = 0; k < 16; k++) {
        temp_offsets[k] += 16;
    }

    b += 16;
    a1 += lda;
    ii++;
}
}
