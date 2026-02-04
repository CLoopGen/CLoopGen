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
    BLASLONG diff = ii - jj;
    if (diff >= 0) {
        if (diff < 1) {
            *(b + diff) = (1.F / (*(a1 + diff)));
        }
    } else {
        *(b + 0) = *(a1 + 0);
    }
    b += 1;
    a1 += lda;
    ii++;
}
}
