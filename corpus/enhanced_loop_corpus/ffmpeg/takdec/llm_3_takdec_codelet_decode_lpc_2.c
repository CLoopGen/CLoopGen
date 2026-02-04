#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *coeffs;
extern int length;
extern int i;
extern unsigned int a3;
extern unsigned int a4;
extern unsigned int a5;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = 2;
    int limit = (length - 3 + stride - 1) / stride;
    for (i = 0; i < limit; i++) {
        int idx = i * stride;
        if (idx >= length - 3) break;
        a3 += coeffs[idx];
        a4 += a3;
        a5 += a4;
        coeffs[idx] = a5;
    }
}
