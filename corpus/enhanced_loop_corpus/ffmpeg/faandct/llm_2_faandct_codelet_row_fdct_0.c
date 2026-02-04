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
    int idx[8];
    for (int j = 0; j < 8; j++) idx[j] = i + j;
    tmp0 = data[idx[0]] + data[idx[7]];
    tmp7 = data[idx[0]] - data[idx[7]];
    tmp1 = data[idx[1]] + data[idx[6]];
    tmp6 = data[idx[1]] - data[idx[6]];
    tmp2 = data[idx[2]] + data[idx[5]];
    tmp5 = data[idx[2]] - data[idx[5]];
    tmp3 = data[idx[3]] + data[idx[4]];
    tmp4 = data[idx[3]] - data[idx[4]];
    tmp10 = tmp0 + tmp3;
    tmp13 = tmp0 - tmp3;
    tmp11 = tmp1 + tmp2;
    tmp12 = tmp1 - tmp2;
    temp[idx[0]] = tmp10 + tmp11;
    temp[idx[4]] = tmp10 - tmp11;
    tmp12 += tmp13;
    tmp12 *= 0.70710678118654757;
    temp[idx[2]] = tmp13 + tmp12;
    temp[idx[6]] = tmp13 - tmp12;
    tmp4 += tmp5;
    tmp5 += tmp6;
    tmp6 += tmp7;
    z2 = tmp4 * (0.54119610014619701 + 0.38268343236508978) - tmp6 * 0.38268343236508978;
    z4 = tmp6 * (1.3065629648763766 - 0.38268343236508978) + tmp4 * 0.38268343236508978;
    tmp5 *= 0.70710678118654757;
    z11 = tmp7 + tmp5;
    z13 = tmp7 - tmp5;
    temp[idx[5]] = z13 + z2;
    temp[idx[3]] = z13 - z2;
    temp[idx[1]] = z11 + z4;
    temp[idx[7]] = z11 - z4;
}
}
