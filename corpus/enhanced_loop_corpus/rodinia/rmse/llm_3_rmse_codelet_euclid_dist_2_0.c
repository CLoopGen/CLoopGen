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
    // Variant 2: Reverse sequential access
    // Iterates from the last element to the first
    for (i = numdims - 1; i >= 0; i--)
        ans += (pt1[i] - pt2[i]) * (pt1[i] - pt2[i]);
}
