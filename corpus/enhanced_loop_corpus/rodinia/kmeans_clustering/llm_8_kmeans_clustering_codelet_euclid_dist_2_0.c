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
    int j;
    for (i = 0; i < numdims; i += 2) {
        float diff1 = pt1[i] - pt2[i];
        ans += diff1 * diff1;
        if (i + 1 < numdims) {
            float diff2 = pt1[i+1] - pt2[i+1];
            ans += diff2 * diff2;
        }
    }
}
