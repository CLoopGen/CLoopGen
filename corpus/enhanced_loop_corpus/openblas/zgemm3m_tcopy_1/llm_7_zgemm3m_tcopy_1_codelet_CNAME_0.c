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
    float local_accum[2] = {0.0f, 0.0f};
    for (i = 0; i < m; i++) {
        a1 = *(a_offset + 0);
        a2 = *(a_offset + 1);
        local_accum[0] += a1;
        local_accum[1] += a2;
        *(b + 0) = local_accum[0] + local_accum[1];
        a_offset += lda;
        b++;
    }
}
