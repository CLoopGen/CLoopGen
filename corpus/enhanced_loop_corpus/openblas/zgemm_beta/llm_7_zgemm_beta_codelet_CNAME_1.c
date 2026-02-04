#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG m;
extern BLASLONG n;
extern float beta_r;
extern float beta_i;
extern BLASLONG ldc;
extern BLASLONG i;
extern BLASLONG j;
extern float *c_offset;
extern float *c_offset1;
extern float atemp1;
extern float atemp2;
extern float atemp3;
extern float atemp4;
extern float btemp1;
extern float btemp2;
extern float btemp3;
extern float btemp4;
extern float ctemp1;
extern float ctemp2;
extern float ctemp3;
extern float ctemp4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = n; j > 0; j--) {
    c_offset1 = c_offset;
    c_offset += ldc;

    BLASLONG vector_count = (m >> 1);
    BLASLONG scalar_count = (m & 1);

    for (BLASLONG k = 0; k < vector_count; k++) {
        float temp_re1 = *(c_offset1 + 0);
        float temp_im1 = *(c_offset1 + 1);
        float temp_re2 = *(c_offset1 + 2);
        float temp_im2 = *(c_offset1 + 3);

        float scaled_re1 = beta_r * temp_re1;
        float scaled_im1 = beta_i * temp_im1;
        float cross_re1 = beta_r * temp_im1;
        float cross_im1 = beta_i * temp_re1;

        float result_re1 = scaled_re1 - scaled_im1;
        float result_im1 = cross_re1 + cross_im1;

        float scaled_re2 = beta_r * temp_re2;
        float scaled_im2 = beta_i * temp_im2;
        float cross_re2 = beta_r * temp_im2;
        float cross_im2 = beta_i * temp_re2;

        float result_re2 = scaled_re2 - scaled_im2;
        float result_im2 = cross_re2 + cross_im2;

        *(c_offset1 + 0) = result_re1;
        *(c_offset1 + 1) = result_im1;
        *(c_offset1 + 2) = result_re2;
        *(c_offset1 + 3) = result_im2;

        c_offset1 += 4;
    }

    for (BLASLONG k = 0; k < scalar_count; k++) {
        float temp_re = *(c_offset1 + 0);
        float temp_im = *(c_offset1 + 1);

        float result_re = beta_r * temp_re - beta_i * temp_im;
        float result_im = beta_r * temp_im + beta_i * temp_re;

        *(c_offset1 + 0) = result_re;
        *(c_offset1 + 1) = result_im;

        c_offset1 += 2;
    }
}
}
