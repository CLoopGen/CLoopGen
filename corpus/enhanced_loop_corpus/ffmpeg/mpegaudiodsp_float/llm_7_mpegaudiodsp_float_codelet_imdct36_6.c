#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *in;
extern int j;
extern float t0;
extern float t1;
extern float t2;
extern float t3;
extern float tmp[18];
extern float *tmp1;
extern float *in1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < 2; j++) {
    tmp1 = tmp + j;
    in1 = in + j;
    float local_t0, local_t1, local_t2, local_t3;
    float in_vals[9];
    for (int k = 0; k < 9; k++) {
        in_vals[k] = in1[2 * k];
    }
    local_t2 = in_vals[8] + in_vals[4] - in_vals[2];
    local_t3 = in_vals[0] + (in_vals[6] * 0.5F);
    local_t1 = in_vals[0] - in_vals[6];
    tmp1[6] = local_t1 - (local_t2 * 0.5F);
    tmp1[16] = local_t1 + local_t2;
    float coeff0 = 0.93969262078590842F;
    float coeff1 = 0.17364817766693036F;
    float coeff2 = 0.76604444311897801F;
    local_t0 = 2 * (coeff0 / 2) * (in_vals[2] + in_vals[4]);
    local_t1 = -2 * (coeff1 / 2) * (in_vals[4] - in_vals[8]);
    local_t2 = -2 * (coeff2 / 2) * (in_vals[2] + in_vals[8]);
    tmp1[10] = local_t3 - local_t0 - local_t2;
    tmp1[2] = local_t3 + local_t0 + local_t1;
    tmp1[14] = local_t3 + local_t2 - local_t1;
    float base_coeff = 0.8660254037844386F;
    tmp1[4] = -2 * (base_coeff / 2) * (in_vals[5] + in_vals[7] - in_vals[1]);
    local_t2 = 2 * (0.98480775301220802F / 2) * (in_vals[1] + in_vals[5]);
    local_t3 = -2 * (0.34202014332566871F / 2) * (in_vals[5] - in_vals[7]);
    local_t0 = 2 * (base_coeff / 2) * in_vals[3];
    local_t1 = -2 * (0.64278760968653936F / 2) * (in_vals[1] + in_vals[7]);
    tmp1[0] = local_t2 + local_t3 + local_t0;
    tmp1[12] = local_t2 + local_t1 - local_t0;
    tmp1[8] = local_t3 - local_t1 - local_t0;
}
}
