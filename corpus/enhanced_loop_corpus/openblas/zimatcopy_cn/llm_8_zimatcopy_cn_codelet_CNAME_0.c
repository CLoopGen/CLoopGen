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
for (i = 0; i < cols; i++) {
    ia = 0;
    for (j = 0; j < rows; j += 2) {
        // Unroll inner loop by factor of 2 to increase computational intensity
        if (j + 1 < rows) {
            // Process two iterations at once
            a0 = aptr[ia];
            a1 = aptr[ia + 1];
            aptr[ia] = alpha_r * a0 - alpha_i * a1;
            aptr[ia + 1] = alpha_r * a1 + alpha_i * a0;

            a0 = aptr[ia + 2];
            a1 = aptr[ia + 3];
            aptr[ia + 2] = alpha_r * a0 - alpha_i * a1;
            aptr[ia + 3] = alpha_r * a1 + alpha_i * a0;

            ia += 4;
        } else {
            // Handle odd row count
            a0 = aptr[ia];
            a1 = aptr[ia + 1];
            aptr[ia] = alpha_r * a0 - alpha_i * a1;
            aptr[ia + 1] = alpha_r * a1 + alpha_i * a0;
            ia += 2;
        }
    }
    aptr += lda;
}
}
