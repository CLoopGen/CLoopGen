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
    float *in_offset = in1 + 2 * 0;
    t3 = in_offset[0] + ((in_offset[6]) * (1.F / 2));
    t1 = in_offset[0] - in_offset[6];
    t2 = in_offset[8] + in_offset[4] - in_offset[2];
    tmp1[6] = t1 - (t2 * 0.5F);
    tmp1[16] = t1 + t2;
    float c0 = 0.93969262078590842F / 2;
    float c1 = 0.17364817766693036F / 2;
    float c2 = 0.76604444311897801F / 2;
    t0 = 2 * c0 * (in_offset[2] + in_offset[4]);
    t1 = -2 * c1 * (in_offset[4] - in_offset[8]);
    t2 = -2 * c2 * (in_offset[2] + in_offset[8]);
    tmp1[10] = t3 - t0 - t2;
    tmp1[2] = t3 + t0 + t1;
    tmp1[14] = t3 + t2 - t1;
    float c3 = 0.8660254037844386F / 2;
    tmp1[4] = -2 * c3 * (in_offset[5] + in_offset[7] - in_offset[1]);
    t2 = 2 * (0.98480775301220802F / 2) * (in_offset[1] + in_offset[5]);
    t3 = -2 * (0.34202014332566871F / 2) * (in_offset[5] - in_offset[7]);
    t0 = 2 * c3 * in_offset[3];
    t1 = -2 * (0.64278760968653936F / 2) * (in_offset[1] + in_offset[7]);
    tmp1[0] = t2 + t3 + t0;
    tmp1[12] = t2 + t1 - t0;
    tmp1[8] = t3 - t1 - t0;
}
}
