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
for (i = 0; i < rows; i++) {
    ia = 0;
    if (cols > 0) {
        for (j = 0; j < cols; j++) {
            a0 = aptr[ia];
            a1 = aptr[ia + 1];
            aptr[ia] = alpha_r * a0 + alpha_i * a1;
            aptr[ia + 1] = -alpha_r * a1 + alpha_i * a0;
            ia += 2;
        }
    }
    aptr += lda;
}
}
