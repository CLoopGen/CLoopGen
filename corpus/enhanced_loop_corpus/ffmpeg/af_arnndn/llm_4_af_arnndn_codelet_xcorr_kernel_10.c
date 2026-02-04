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
        float tmp;
        tmp = *x++;
        y_3 = *y++;
        if (tmp > 0.0f) {
            sum[0] += tmp * y_0;
            sum[1] += tmp * y_1;
            sum[2] += tmp * y_2;
            sum[3] += tmp * y_3;
        }
        tmp = *x++;
        y_0 = *y++;
        if (tmp > 0.0f) {
            sum[0] += tmp * y_1;
            sum[1] += tmp * y_2;
            sum[2] += tmp * y_3;
            sum[3] += tmp * y_0;
        }
        tmp = *x++;
        y_1 = *y++;
        if (tmp > 0.0f) {
            sum[0] += tmp * y_2;
            sum[1] += tmp * y_3;
            sum[2] += tmp * y_0;
            sum[3] += tmp * y_1;
        }
        tmp = *x++;
        y_2 = *y++;
        if (tmp > 0.0f) {
            sum[0] += tmp * y_3;
            sum[1] += tmp * y_0;
            sum[2] += tmp * y_1;
            sum[3] += tmp * y_2;
        }
    }
}
