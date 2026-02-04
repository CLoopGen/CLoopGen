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
    float temp = 0.0f;
    for (i = 0; i < numdims; i++) {
        float diff = pt1[i] - pt2[i];
        temp += diff * diff;
    }
    ans += temp;
}
