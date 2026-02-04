#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float matrix_coeffs[8];
extern float *su1;
extern float *su2;
extern int *prev_code;
extern int *curr_code;
extern int i;
extern int nsample;
extern int band;
extern float mc1_l;
extern float mc1_r;
extern float mc2_l;
extern float mc2_r;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0 , band = 0; band < 4 * 256; band += 256 , i++) {
    int s1 = prev_code[i];
    int s2 = curr_code[i];
    nsample = band;
    if (s1 != s2) {
        float temp_mc1_l = matrix_coeffs[s1 * 2];
        float temp_mc1_r = matrix_coeffs[s1 * 2 + 1];
        float temp_mc2_l = matrix_coeffs[s2 * 2];
        float temp_mc2_r = matrix_coeffs[s2 * 2 + 1];
        mc1_l = temp_mc1_l;
        mc1_r = temp_mc1_r;
        mc2_l = temp_mc2_l;
        mc2_r = temp_mc2_r;
        for (; nsample < band + 8; nsample++) {
            float c1 = su1[nsample];
            float c2 = su2[nsample];
            float alpha = (nsample - band) * 0.125;
            float coef_l = mc1_l + alpha * (mc2_l - mc1_l);
            float coef_r = mc1_r + alpha * (mc2_r - mc1_r);
            float new_c2 = c1 * coef_l + c2 * coef_r;
            su2[nsample] = c1 * 2.f - new_c2;
            su1[nsample] = new_c2;
        }
    }
    switch (s2) {
      case 0:
        for (; nsample < band + 256; nsample++) {
            float c1 = su1[nsample];
            float c2 = su2[nsample];
            su2[nsample] = (c1 - c2) * 2.f;
            su1[nsample] = c2 * 2.f;
        }
        break;
      case 1:
        for (; nsample < band + 256; nsample++) {
            float c1 = su1[nsample];
            float c2 = su2[nsample];
            su2[nsample] = c2 * -2.f;
            su1[nsample] = (c1 + c2) * 2.f;
        }
        break;
      case 2:
      case 3:
        for (; nsample < band + 256; nsample++) {
            float c1 = su1[nsample];
            float c2 = su2[nsample];
            su1[nsample] = c1 + c2;
            su2[nsample] = c1 - c2;
        }
        break;
      default:
        ((void)0);
    }
}
}
