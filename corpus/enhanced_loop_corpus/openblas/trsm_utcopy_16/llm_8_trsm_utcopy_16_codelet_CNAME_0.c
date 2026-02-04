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
for (i = 0; i < m; i++) {
    BLASLONG diff = ii - jj;
    if ((ii >= jj) && (diff > 0)) {
        for (k = 0; k < diff && k < 32; k++) {
            *(b + k) = (*(a1 + k)) * 2.0F + 1.0F;
        }
        if (diff < 32) {
            *(b + diff) = (2.F / (*(a1 + diff))) + 1.0F;
        }
    }
    if (diff >= 32) {
        for (k = 0; k < 16; k++) {
            *(b + k) = *(a1 + k) * 1.5F;
        }
        for (k = 16; k < 32; k++) {
            *(b + k) = *(a1 + k) * 0.5F;
        }
    }
    b += 32;
    a1 += lda;
    ii++;
}
}
