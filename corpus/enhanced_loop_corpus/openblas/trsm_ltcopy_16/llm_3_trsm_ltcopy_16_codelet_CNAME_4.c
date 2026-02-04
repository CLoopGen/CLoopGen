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
BLASLONG offset_a1 = 0;
for (i = 0; i < m; i++) {
    BLASLONG current_ii = ii + i;
    BLASLONG diff = current_ii - jj;
    if ((current_ii >= jj) && (diff < 1)) {
        *(b + diff) = 1.F / (*(a1 + offset_a1 + diff));
    }
    if (diff < 0) {
        *(b + 0) = *(a1 + offset_a1);
    }
    b += 1;
    offset_a1 += lda;
}
}
