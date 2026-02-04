#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *dp1;
extern double *dp2;
extern double s;
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (i = 0; i < len; i += 2) {
        (*dp1) += s * (*dp2);
        dp1 += 1;
        dp2 += 1;
        if (i + 1 < len) {
            (*dp1) += s * (*dp2);
            dp1 += 1;
            dp2 += 1;
        }
    }
}
