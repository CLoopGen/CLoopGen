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
for (i = 0; i < 4; i++) {
    int s1 = prev_code[i];
    int s2 = curr_code[i];
    for (band = i * 256; band < (i + 1) * 256; band++) {
        nsample = band;
        if (s1 != s2 && (nsample % 256) < 8) {
            mc1_l = matrix_coeffs[s1 * 2];
            mc1_r = matrix_coeffs[s1 * 2 + 1];
            mc2_l = matrix_coeffs[s2 * 2];
            mc2_r = matrix_coeffs[s2 * 2 + 1];
            float c1 = su1[nsample];
            float c2 = su2[nsample];
            c2 = c1 * ((mc1_l) + (nsample - band) * 0.125 * ((mc2_l) - (mc1_l))) + c2 * ((mc1_r) + (nsample - band) * 0.125 * ((mc2_r) - (mc1_r)));
            su1[nsample] = c2;
            su2[nsample] = c1 * 2. - c2;
        }
        switch (s2) {
          case 0:
            if ((nsample % 256) >= 8) {
                float c1 = su1[nsample];
                float c2 = su2[nsample];
                su1[nsample] = c2 * 2.;
                su2[nsample] = (c1 - c2) * 2.;
            }
            break;
          case 1:
            if ((nsample % 256) >= 8) {
                float c1 = su1[nsample];
                float c2 = su2[nsample];
                su1[nsample] = (c1 + c2) * 2.;
                su2[nsample] = c2 * -2.;
            }
            break;
          case 2:
          case 3:
            if ((nsample % 256) >= 8) {
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
}
