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
    int outer = numdims / 2;
    int remainder = numdims % 2;
    for (i = 0; i < outer; i++) {
        ans += (pt1[2*i] - pt2[2*i]) * (pt1[2*i] - pt2[2*i]);
        ans += (pt1[2*i+1] - pt2[2*i+1]) * (pt1[2*i+1] - pt2[2*i+1]);
    }
    if (remainder) {
        ans += (pt1[numdims-1] - pt2[numdims-1]) * (pt1[numdims-1] - pt2[numdims-1]);
    }
}
