#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *pt1;
extern float *pt2;
extern int numdims;
extern int i;
extern float ans;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float sum1 = 0.0f, sum2 = 0.0f, sum3 = 0.0f;
    int remainder = numdims % 3;
    int trip_count = numdims - remainder;

    for (i = 0; i < trip_count; i += 3) {
        sum1 += (pt1[i]   - pt2[i])   * (pt1[i]   - pt2[i]);
        sum2 += (pt1[i+1] - pt2[i+1]) * (pt1[i+1] - pt2[i+1]);
        sum3 += (pt1[i+2] - pt2[i+2]) * (pt1[i+2] - pt2[i+2]);
    }

    for (i = trip_count; i < numdims; i++) {
        ans += (pt1[i] - pt2[i]) * (pt1[i] - pt2[i]);
    }

    ans += sum1 + sum2 + sum3;
}
