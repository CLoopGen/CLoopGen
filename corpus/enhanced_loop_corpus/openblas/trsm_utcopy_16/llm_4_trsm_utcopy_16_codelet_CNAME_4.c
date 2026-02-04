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
    if (diff == 0) {
        *(b + 0) = (1.F / (*(a1 + 0)));
    } else {
        for (k = 0; k < diff; k++) {
            *(b + k) = *(a1 + k);
        }
        if (diff > 0) {
            *(b + diff) = (1.F / (*(a1 + diff)));
        }
    }
    b += 1;
    a1 += lda;
    ii++;
}
}
