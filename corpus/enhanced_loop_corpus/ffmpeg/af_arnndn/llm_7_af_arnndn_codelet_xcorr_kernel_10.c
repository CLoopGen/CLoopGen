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
float s0 = sum[0], s1 = sum[1], s2 = sum[2], s3 = sum[3];
for (j = 0; j < len - 3; j += 4) {
    float tmp;
    tmp = *x++;
    y_3 = *y++;
    s0 += tmp * y_0;
    s1 += tmp * y_1;
    s2 += tmp * y_2;
    s3 += tmp * y_3;
    tmp = *x++;
    y_0 = *y++;
    s0 += tmp * y_1;
    s1 += tmp * y_2;
    s2 += tmp * y_3;
    s3 += tmp * y_0;
    tmp = *x++;
    y_1 = *y++;
    s0 += tmp * y_2;
    s1 += tmp * y_3;
    s2 += tmp * y_0;
    s3 += tmp * y_1;
    tmp = *x++;
    y_2 = *y++;
    s0 += tmp * y_3;
    s1 += tmp * y_0;
    s2 += tmp * y_1;
    s3 += tmp * y_2;
}
sum[0] = s0; sum[1] = s1; sum[2] = s2; sum[3] = s3;
}
