#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *dp1;
extern double *dp2;
extern double *out;
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len; i += 2) {
        if (i + 1 < len) {
            out[0] = dp1[0] + dp2[0];
            out[1] = dp1[1] + dp2[1];
            out += 2; dp1 += 2; dp2 += 2;
        } else {
            (*out++) = (*dp1++) + (*dp2++);
        }
    }
}
