#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG m;
extern BLASLONG lda;
extern float *b;
extern BLASLONG i;
extern float *a_offset;
extern float a1;
extern float a2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (m > 0) {
    for (BLASLONG outer = 0; outer < m; outer++) {
        {
            a1 = *(a_offset + 0);
            a2 = *(a_offset + 1);
            *(b + 0) = ((a1) + (a2));
            a_offset += lda;
            b++;
        }
    }
} else {
    for (BLASLONG empty = 0; empty < 0; empty++) {
    }
}
}
