#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG m;
extern BLASLONG lda;
extern float *b;
extern BLASLONG i;
extern BLASLONG ii;
extern BLASLONG jj;
extern float *a1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < m; i++) {
    BLASLONG offset = ii - jj;
    if (offset >= 0 && offset < 1) {
        float reciprocal = 1.F / (*(a1 + offset));
        *(b + offset) = reciprocal * reciprocal; // Increased arithmetic intensity: square the reciprocal
    }
    if (offset < 0) {
        float val = *(a1 + 0);
        *(b + 0) = val * val + 1.F; // More operations: square and add constant
    }
    b += 1;
    a1 += lda;
    ii++;
}
}
