#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *coeffs;
extern int length;
extern int i;
extern unsigned int a1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < (length - 1) >> 2; i++) {
        *coeffs += a1 + 1;
        coeffs[1] += (unsigned int)*coeffs;
        a1 = coeffs[1] + *coeffs;
        coeffs[2] += a1;
        coeffs[3] += coeffs[2];
        coeffs += 4;
    }
}
