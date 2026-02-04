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
    // Variant 1: Strided memory access with stride of 2
    // Processes elements at even indices only, effectively halving the effective numdims
    int n = numdims / 2;
    for (i = 0; i < n; i++) {
        int idx = i * 2;
        ans += (pt1[idx] - pt2[idx]) * (pt1[idx] - pt2[idx]);
    }
}
