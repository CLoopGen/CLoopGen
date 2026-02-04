#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *dp;
extern double s;
extern double *out;
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len * 2; i += 2) { // Double the trip count and unroll by factor 2
        if (i < len) {
            (*out++) = s * (*dp++);
        }
        if (i + 1 < len) {
            (*out++) = s * (*dp++);
        }
    }
}
