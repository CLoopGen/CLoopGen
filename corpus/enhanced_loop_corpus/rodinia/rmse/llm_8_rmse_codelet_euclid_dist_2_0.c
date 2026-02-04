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
    int step = 2;
    for (i = 0; i < numdims; i += step) {
        ans += (pt1[i] - pt2[i]) * (pt1[i] - pt2[i]);
        if (i + 1 < numdims)
            ans += (pt1[i+1] - pt2[i+1]) * (pt1[i+1] - pt2[i+1]);
    }
}
