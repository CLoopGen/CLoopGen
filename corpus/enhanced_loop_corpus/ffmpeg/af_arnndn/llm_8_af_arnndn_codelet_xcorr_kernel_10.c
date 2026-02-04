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
    for (j = 0; j < len - 7; j += 8) {
        float tmp0, tmp1, tmp2, tmp3;
        
        // Load four values from x and y in bulk
        tmp0 = *x++;
        y_3 = *y++;
        sum[0] += tmp0 * y_0;
        sum[1] += tmp0 * y_1;
        sum[2] += tmp0 * y_2;
        sum[3] += tmp0 * y_3;

        tmp1 = *x++;
        y_0 = *y++;
        sum[0] += tmp1 * y_1;
        sum[1] += tmp1 * y_2;
        sum[2] += tmp1 * y_3;
        sum[3] += tmp1 * y_0;

        tmp2 = *x++;
        y_1 = *y++;
        sum[0] += tmp2 * y_2;
        sum[1] += tmp2 * y_3;
        sum[2] += tmp2 * y_0;
        sum[3] += tmp2 * y_1;

        tmp3 = *x++;
        y_2 = *y++;
        sum[0] += tmp3 * y_3;
        sum[1] += tmp3 * y_0;
        sum[2] += tmp3 * y_1;
        sum[3] += tmp3 * y_2;

        // Second unrolled iteration (additional computational intensity)
        tmp0 = *x++;
        y_3 = *y++;
        sum[0] += tmp0 * y_0;
        sum[1] += tmp0 * y_1;
        sum[2] += tmp0 * y_2;
        sum[3] += tmp0 * y_3;

        tmp1 = *x++;
        y_0 = *y++;
        sum[0] += tmp1 * y_1;
        sum[1] += tmp1 * y_2;
        sum[2] += tmp1 * y_3;
        sum[3] += tmp1 * y_0;

        tmp2 = *x++;
        y_1 = *y++;
        sum[0] += tmp2 * y_2;
        sum[1] += tmp2 * y_3;
        sum[2] += tmp2 * y_0;
        sum[3] += tmp2 * y_1;

        tmp3 = *x++;
        y_2 = *y++;
        sum[0] += tmp3 * y_3;
        sum[1] += tmp3 * y_0;
        sum[2] += tmp3 * y_1;
        sum[3] += tmp3 * y_2;
    }
}
