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
    int diff = ii - jj;
    if (diff >= 0 && diff < 2) {
        *(b + diff) = (1.F / (*(a1 + diff)));
        if (diff == 0) {
            *(b + 1) = *(a1 + 1);
        }
    } else if (diff < 0) {
        *(b + 0) = *(a1 + 0);
        *(b + 1) = *(a1 + 1);
    }
    b += 2;
    a1 += lda;
    ii++;
}
}
