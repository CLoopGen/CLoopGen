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
BLASLONG temp_index = ii - jj;
for (i = 0; i < m; i++) {
    BLASLONG offset = temp_index + i; // Introduce loop-carried dependency via induction
    if ((ii >= jj) && (offset < 1)) {
        *(b + offset) = (1.F / (*(a1 + offset)));
    }
    if (offset < 0) {
        *(b + 0) = *(a1 + 0);
    }
    b += 1;
    a1 += lda;
    // ii is no longer updated inside loop; dependency on ii now only initial
}
}
