#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *v2;
extern int len;
extern int i;
extern unsigned int *v1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len; i++) {
        int t = v1[i] - v2[i];
        v1[i] += v2[i];
        if (t >= 0) {  // Only write back t if non-negative
            v2[i] = t;
        } else {
            v2[i] = 0;  // Clamp negative values to zero
        }
    }
}
