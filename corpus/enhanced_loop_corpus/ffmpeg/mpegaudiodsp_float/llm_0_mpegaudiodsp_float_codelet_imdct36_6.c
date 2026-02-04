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
    for (int k = 0; k < 1; k++) {
        tmp1 = tmp + j;
        in1 = in + j;
        t2 = in1[2 * 4] + in1[2 * 8] - in1[2 * 2];
        t3 = in1[2 * 0] + ((in1[2 * 6]) * (1.F / (1 << (1))));
        t1 = in1[2 * 0] - in1[2 * 6];
        tmp1[6] = t1 - ((t2) * (1.F / (1 << (1))));
        tmp1[16] = t1 + t2;
        t0 = ((2) * (((float)(0.93969262078590842 / 2))) * (in1[2 * 2] + in1[2 * 4]));
        t1 = ((1) * (-2 * ((float)(0.17364817766693036 / 2))) * (in1[2 * 4] - in1[2 * 8]));
        t2 = ((2) * (-((float)(0.76604444311897801 / 2))) * (in1[2 * 2] + in1[2 * 8]));
        tmp1[10] = t3 - t0 - t2;
        tmp1[2] = t3 + t0 + t1;
        tmp1[14] = t3 + t2 - t1;
        tmp1[4] = ((2) * (-((float)(0.8660254037844386 / 2))) * (in1[2 * 5] + in1[2 * 7] - in1[2 * 1]));
        t2 = ((2) * (((float)(0.98480775301220802 / 2))) * (in1[2 * 1] + in1[2 * 5]));
        t3 = ((1) * (-2 * ((float)(0.34202014332566871 / 2))) * (in1[2 * 5] - in1[2 * 7]));
        t0 = ((2) * (((float)(0.8660254037844386 / 2))) * (in1[2 * 3]));
        t1 = ((2) * (-((float)(0.64278760968653936 / 2))) * (in1[2 * 1] + in1[2 * 7]));
        tmp1[0] = t2 + t3 + t0;
        tmp1[12] = t2 + t1 - t0;
        tmp1[8] = t3 - t1 - t0;
    }
}
}
