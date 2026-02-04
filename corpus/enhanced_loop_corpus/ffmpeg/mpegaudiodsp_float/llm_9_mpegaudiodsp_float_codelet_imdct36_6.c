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
for (j = 0; j < 1; j++) {
    tmp1 = tmp + j;
    in1 = in + j;
    float a = in1[8], b = in1[16], c = in1[4], d = in1[0], e = in1[12];
    float f = in1[10], g = in1[14], h = in1[2], i_val = in1[6];
    t2 = a + b - c;
    t3 = d + (i_val * 0.5F);
    t1 = d - i_val;
    tmp1[6] = t1 - (t2 * 0.5F);
    tmp1[16] = t1 + t2;
    t0 = 0.93969262078590842F * (c + a);
    t1 = -0.17364817766693036F * (a - b);
    t2 = -0.76604444311897801F * (c + b);
    tmp1[10] = t3 - t0 - t2;
    tmp1[2] = t3 + t0 + t1;
    tmp1[14] = t3 + t2 - t1;
    tmp1[4] = -0.8660254037844386F * (f + g - h);
    t2 = 0.98480775301220802F * (h + f);
    t3 = -0.34202014332566871F * (f - g);
    t0 = 0.8660254037844386F * in1[6];
    t1 = -0.64278760968653936F * (h + g);
    tmp1[0] = t2 + t3 + t0;
    tmp1[12] = t2 + t1 - t0;
    tmp1[8] = t3 - t1 - t0;
}
}
