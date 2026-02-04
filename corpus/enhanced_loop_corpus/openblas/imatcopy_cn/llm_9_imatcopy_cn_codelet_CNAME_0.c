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
for (i = 0; i < cols; i++) {
    float beta = alpha * alpha;
    for (j = 0; j < rows; j++) {
        aptr[j] = beta * aptr[j] + alpha;
    }
    aptr += lda;
}
}
