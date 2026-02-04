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

    mc1_l = matrix_coeffs[s1 * 2];
    mc1_r = matrix_coeffs[s1 * 2 + 1];
    mc2_l = matrix_coeffs[s2 * 2];
    mc2_r = matrix_coeffs[s2 * 2 + 1];

    for (; nsample < band + 8; nsample++) {
        float c1 = su1[nsample];
        float c2 = su2[nsample];
        float t = (nsample - band) * 0.125;
        float interp_l = mc1_l + t * (mc2_l - mc1_l);
        float interp_r = mc1_r + t * (mc2_r - mc1_r);
        float mixed = c1 * interp_l + c2 * interp_r;
        su1[nsample] = mixed;
        su2[nsample] = c1 * 2.0f - mixed;
    }

    if (s2 == 0) {
        for (; nsample < band + 256; nsample++) {
            float c1 = su1[nsample];
            float c2 = su2[nsample];
            su1[nsample] = c2 * 2.0f;
            su2[nsample] = (c1 - c2) * 2.0f;
        }
    } else if (s2 == 1) {
        for (; nsample < band + 256; nsample++) {
            float c1 = su1[nsample];
            float c2 = su2[nsample];
            su1[nsample] = (c1 + c2) * 2.0f;
            su2[nsample] = c2 * -2.0f;
        }
    } else if (s2 == 2 || s2 == 3) {
        for (; nsample < band + 256; nsample++) {
            float c1 = su1[nsample];
            float c2 = su2[nsample];
            su1[nsample] = c1 + c2;
            su2[nsample] = c1 - c2;
        }
    }
}
}
