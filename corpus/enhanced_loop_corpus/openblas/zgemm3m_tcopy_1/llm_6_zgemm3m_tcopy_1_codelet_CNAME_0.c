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
    BLASLONG temp_index = 0;
    float prev_sum = 0.0f;
    for (i = 0; i < m; i++) {
        a1 = *(a_offset + 0);
        a2 = *(a_offset + 1);
        temp_index = i * lda;
        a_offset = b + temp_index;
        *(b + 0) = ((a1) + (a2)) + prev_sum;
        prev_sum = *(b + 0);
        b++;
    }
}
