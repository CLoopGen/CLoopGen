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
for (i = 0; i < 8 * 4; i += 8) {
    tmp0 = data[0 + i] + data[7 + i];
    tmp7 = data[0 + i] - data[7 + i];
    tmp1 = data[1 + i] + data[6 + i];
    tmp6 = data[1 + i] - data[6 + i];
    tmp2 = data[2 + i] + data[5 + i];
    tmp5 = data[2 + i] - data[5 + i];
    tmp3 = data[3 + i] + data[4 + i];
    tmp4 = data[3 + i] - data[4 + i];
    tmp10 = tmp0 + tmp3;
    tmp13 = tmp0 - tmp3;
    tmp11 = tmp1 + tmp2;
    tmp12 = tmp1 - tmp2;
    temp[0 + i] = tmp10 + tmp11;
    temp[4 + i] = tmp10 - tmp11;
    z2 = tmp4 * 0.9238795325112867 - tmp6 * 0.38268343236508978;
    z4 = tmp6 * 0.9238795325112867 + tmp4 * 0.38268343236508978;
    tmp5 *= 0.70710678118654757;
    z11 = tmp7 + tmp5;
    z13 = tmp7 - tmp5;
    temp[5 + i] = z13 + z2;
    temp[3 + i] = z13 - z2;
    temp[1 + i] = z11 + z4;
    temp[7 + i] = z11 - z4;
    temp[2 + i] = tmp13 + (tmp12 + tmp13) * 0.70710678118654757;
    temp[6 + i] = tmp13 - (tmp12 + tmp13) * 0.70710678118654757;
}
}
