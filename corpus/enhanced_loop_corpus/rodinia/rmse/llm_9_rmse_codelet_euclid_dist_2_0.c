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
    float sum1 = 0.0f, sum2 = 0.0f;
    int limit = numdims - (numdims % 4);
    for (i = 0; i < limit; i += 4) {
        sum1 += (pt1[i] - pt2[i]) * (pt1[i] - pt2[i]) +
                (pt1[i+1] - pt2[i+1]) * (pt1[i+1] - pt2[i+1]);
        sum2 += (pt1[i+2] - pt2[i+2]) * (pt1[i+2] - pt2[i+2]) +
                (pt1[i+3] - pt2[i+3]) * (pt1[i+3] - pt2[i+3]);
    }
    ans += sum1 + sum2;
    for (; i < numdims; i++)
        ans += (pt1[i] - pt2[i]) * (pt1[i] - pt2[i]);
}
