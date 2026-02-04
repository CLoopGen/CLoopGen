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
    float *row_ptr = aptr;
    for (j = 0; j < rows; j++) {
        row_ptr[0] = alpha * row_ptr[0];
        row_ptr++;
    }
    aptr += lda;
}
}
