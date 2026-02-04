#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG rows;
extern BLASLONG cols;
extern float alpha_r;
extern float alpha_i;
extern BLASLONG lda;
extern BLASLONG i;
extern BLASLONG j;
extern BLASLONG ia;
extern float *aptr;
extern float a0;
extern float a1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
BLASLONG offset;
for (i = 0; i < rows; i++) {
    offset = i * lda;
    for (j = 0; j < cols; j++) {
        ia = offset + 2 * j;
        a0 = ((float*)aptr)[ia];
        a1 = ((float*)aptr)[ia + 1];
        ((float*)aptr)[ia] = alpha_r * a0 - alpha_i * a1;
        ((float*)aptr)[ia + 1] = alpha_r * a1 + alpha_i * a0;
    }
}
}
