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
    if ((ii >= jj) && (ii - jj < 1)) {
        *(b + ii - jj) = (1.F / (*(a1 + ii - jj)));
    }
    if (ii - jj < 0) {
        *(b + 0) = *(a1 + 0);
    }
    b += 1;
    a1 += lda;
    ii++;
}

}
