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
    if (diff < 2 && diff >= 0) {
        for (k = 0; k < diff; k++) {
            *(b + k) = *(a1 + k);
        }
        *(b + diff) = (1.F / (*(a1 + diff)));
    } else {
        *(b + 0) = *(a1 + 0);
        *(b + 1) = *(a1 + 1);
    }
    b += 2;
    a1 += lda;
    ii++;
}
}
