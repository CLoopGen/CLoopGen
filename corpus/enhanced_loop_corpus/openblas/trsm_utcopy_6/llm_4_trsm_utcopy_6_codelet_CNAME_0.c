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
for (i = 0; i < m; i++) {
    BLASLONG diff = ii - jj;
    if (diff > 0) {
        for (k = 0; k < diff && k < 4; k++) {
            *(b + k) = *(a1 + k);
        }
        if (diff < 4) {
            *(b + diff) = (1.F / (*(a1 + diff)));
        } else {
            *(b + 0) = *(a1 + 0);
            *(b + 1) = *(a1 + 1);
            *(b + 2) = *(a1 + 2);
            *(b + 3) = *(a1 + 3);
        }
    } else {
        *(b + 0) = (1.F / (*(a1 + 0)));
    }
    b += 4;
    a1 += lda;
    ii++;
}
}
