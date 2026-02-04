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
        float *mc_ptr1 = &matrix_coeffs[s1 * 2];
        float *mc_ptr2 = &matrix_coeffs[s2 * 2];
        mc1_l = mc_ptr1[0];
        mc1_r = mc_ptr1[1];
        mc2_l = mc_ptr2[0];
        mc2_r = mc_ptr2[1];
        for (; nsample < band + 8; nsample++) {
            ptrdiff_t idx = nsample;
            float c1 = su1[idx];
            float c2 = su2[idx];
            float delta_t = 0.125f * (float)(idx - band);
            float interp_l = mc1_l + delta_t * (mc2_l - mc1_l);
            float interp_r = mc1_r + delta_t * (mc2_r - mc1_r);
            c2 = c1 * interp_l + c2 * interp_r;
            su1[idx] = c2;
            su2[idx] = c1 * 2.0f - c2;
        }
    }
    switch (s2) {
      case 0:
        for (; nsample < band + 256; nsample++) {
            ptrdiff_t idx = nsample;
            float c1 = su1[idx];
            float c2 = su2[idx];
            float out1 = c2 * 2.0f;
            float out2 = (c1 - c2) * 2.0f;
            su1[idx] = out1;
            su2[idx] = out2;
        }
        break;
      case 1:
        for (; nsample < band + 256; nsample++) {
            ptrdiff_t idx = nsample;
            float c1 = su1[idx];
            float c2 = su2[idx];
            float out1 = (c1 + c2) * 2.0f;
            float out2 = c2 * -2.0f;
            su1[idx] = out1;
            su2[idx] = out2;
        }
        break;
      case 2:
      case 3:
        for (; nsample < band + 256; nsample++) {
            ptrdiff_t idx = nsample;
            float c1 = su1[idx];
            float c2 = su2[idx];
            su1[idx] = c1 + c2;
            su2[idx] = c1 - c2;
        }
        break;
      default:
        ((void)0);
    }
}
}
