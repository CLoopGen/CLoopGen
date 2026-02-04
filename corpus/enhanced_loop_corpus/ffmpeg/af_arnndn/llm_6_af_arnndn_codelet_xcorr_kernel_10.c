#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *x;
extern  float *y;
extern float sum[4];
extern int len;
extern float y_0;
extern float y_1;
extern float y_2;
extern float y_3;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < len - 3; j += 4) {
    float tmp0, tmp1, tmp2, tmp3;
    tmp0 = *x++;
    tmp1 = *x++;
    tmp2 = *x++;
    tmp3 = *x++;

    y_3 = *y++;
    y_0 = *y++;
    y_1 = *y++;
    y_2 = *y++;

    sum[0] += tmp0 * y_0 + tmp1 * y_1 + tmp2 * y_2 + tmp3 * y_3;
    sum[1] += tmp0 * y_1 + tmp1 * y_2 + tmp2 * y_3 + tmp3 * y_0;
    sum[2] += tmp0 * y_2 + tmp1 * y_3 + tmp2 * y_0 + tmp3 * y_1;
    sum[3] += tmp0 * y_3 + tmp1 * y_0 + tmp2 * y_1 + tmp3 * y_2;
}
}
