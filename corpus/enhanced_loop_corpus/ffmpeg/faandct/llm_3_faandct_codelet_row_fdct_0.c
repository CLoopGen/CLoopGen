#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float FLOAT;

extern FLOAT temp[64];
extern int16_t *data;
extern FLOAT tmp0;
extern FLOAT tmp1;
extern FLOAT tmp2;
extern FLOAT tmp3;
extern FLOAT tmp4;
extern FLOAT tmp5;
extern FLOAT tmp6;
extern FLOAT tmp7;
extern FLOAT tmp10;
extern FLOAT tmp11;
extern FLOAT tmp12;
extern FLOAT tmp13;
extern FLOAT z2;
extern FLOAT z4;
extern FLOAT z11;
extern FLOAT z13;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8 * 8; i += 8) {
    const int stride = 8;
    int base_idx = i;
    FLOAT *d = (FLOAT*)data; // Treat data as FLOAT for strided access consistency
    tmp0 = d[base_idx + 0*stride] + d[base_idx + 7*stride];
    tmp7 = d[base_idx + 0*stride] - d[base_idx + 7*stride];
    tmp1 = d[base_idx + 1*stride] + d[base_idx + 6*stride];
    tmp6 = d[base_idx + 1*stride] - d[base_idx + 6*stride];
    tmp2 = d[base_idx + 2*stride] + d[base_idx + 5*stride];
    tmp5 = d[base_idx + 2*stride] - d[base_idx + 5*stride];
    tmp3 = d[base_idx + 3*stride] + d[base_idx + 4*stride];
    tmp4 = d[base_idx + 3*stride] - d[base_idx + 4*stride];
    tmp10 = tmp0 + tmp3;
    tmp13 = tmp0 - tmp3;
    tmp11 = tmp1 + tmp2;
    tmp12 = tmp1 - tmp2;
    temp[base_idx + 0*stride] = tmp10 + tmp11;
    temp[base_idx + 4*stride] = tmp10 - tmp11;
    tmp12 += tmp13;
    tmp12 *= 0.70710678118654757;
    temp[base_idx + 2*stride] = tmp13 + tmp12;
    temp[base_idx + 6*stride] = tmp13 - tmp12;
    tmp4 += tmp5;
    tmp5 += tmp6;
    tmp6 += tmp7;
    z2 = tmp4 * (0.54119610014619701 + 0.38268343236508978) - tmp6 * 0.38268343236508978;
    z4 = tmp6 * (1.3065629648763766 - 0.38268343236508978) + tmp4 * 0.38268343236508978;
    tmp5 *= 0.70710678118654757;
    z11 = tmp7 + tmp5;
    z13 = tmp7 - tmp5;
    temp[base_idx + 5*stride] = z13 + z2;
    temp[base_idx + 3*stride] = z13 - z2;
    temp[base_idx + 1*stride] = z11 + z4;
    temp[base_idx + 7*stride] = z11 - z4;
}
}
