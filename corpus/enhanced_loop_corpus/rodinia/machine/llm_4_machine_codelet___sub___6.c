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
    for (i = 0; i < len; i++) {
        double diff = (*dp1++) - (*dp2++);
        if (diff >= 0) {
            *out++ = diff;
        } else {
            *out++ = 0;
        }
    }
}
