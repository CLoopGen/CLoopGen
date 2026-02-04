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
    // Strided memory access: process elements with a stride of 2, effectively skipping every other element
    // Adjust loop bound to ensure we don't exceed array limits with striding
    int stride = 2;
    int bound = (len - 3) / stride;
    for (j = 0; j < bound; j++) {
        int idx = j * stride * 4; // scaled index for grouped processing under stride
        float tmp;

        if (idx + 6 >= len) break; // safety check to prevent out-of-bounds

        tmp = x[idx];
        y_3 = y[idx];
        sum[0] += tmp * y_0;
        sum[1] += tmp * y_1;
        sum[2] += tmp * y_2;
        sum[3] += tmp * y_3;

        tmp = x[idx + 2];
        y_0 = y[idx + 2];
        sum[0] += tmp * y_1;
        sum[1] += tmp * y_2;
        sum[2] += tmp * y_3;
        sum[3] += tmp * y_0;

        tmp = x[idx + 4];
        y_1 = y[idx + 4];
        sum[0] += tmp * y_2;
        sum[1] += tmp * y_3;
        sum[2] += tmp * y_0;
        sum[3] += tmp * y_1;

        tmp = x[idx + 6];
        y_2 = y[idx + 6];
        sum[0] += tmp * y_3;
        sum[1] += tmp * y_0;
        sum[2] += tmp * y_1;
        sum[3] += tmp * y_2;
    }
}
