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
    for (i = 0; i < m; i += 2) {
        a1 = *(a_offset + 0);
        a2 = *(a_offset + 1);
        *(b + 0) = ((a1) + (a2));
        if (i + 1 < m) {
            float b1 = *(a_offset + lda + 0);
            float b2 = *(a_offset + lda + 1);
            *(b + 1) = (b1 + b2);
        }
        a_offset += 2 * lda;
        b += 2;
    }
}
