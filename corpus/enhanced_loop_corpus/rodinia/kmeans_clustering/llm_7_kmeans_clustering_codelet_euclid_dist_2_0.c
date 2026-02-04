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
    if (numdims > 0) {
        ans += (pt1[0] - pt2[0]) * (pt1[0] - pt2[0]);
        for (i = 1; i < numdims; i++) {
            float diff_prev = pt1[i-1] - pt2[i-1];
            float diff_curr = pt1[i] - pt2[i];
            ans += diff_curr * diff_curr + diff_prev * diff_prev;
            i++;
            if (i < numdims)
                ans -= diff_prev * diff_prev;
        }
    }
}
