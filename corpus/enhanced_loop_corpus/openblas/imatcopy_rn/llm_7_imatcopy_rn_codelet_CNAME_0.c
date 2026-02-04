#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG rows;
extern BLASLONG cols;
extern float alpha;
extern BLASLONG lda;
extern BLASLONG i;
extern BLASLONG j;
extern float *aptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
float prev_val = 0.0f;
for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
        float current = aptr[j];
        aptr[j] = alpha * current + prev_val;
        prev_val = current;
    }
    aptr += lda;
}
}
