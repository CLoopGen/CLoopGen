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
    // Variant 1: Strided memory access (stride of 2)
    for (i = 0; i < len; i += 2) {
        int t = v1[i] - v2[i];
        v1[i] += v2[i];
        v2[i] = t;
    }
}
