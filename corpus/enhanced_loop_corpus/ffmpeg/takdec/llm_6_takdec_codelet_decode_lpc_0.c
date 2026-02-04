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
    for (i = 0; i < length - 1 >> 1; i++) {
        int32_t temp = *coeffs;
        *coeffs += a1;
        coeffs[1] += (unsigned int)temp;
        a1 = coeffs[1];
        coeffs += 2;
    }
}
