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
    for (i = 0; i < length - 1 >> 1 && a1 != 0; i++) {
        *coeffs += a1;
        unsigned int temp = (unsigned int)*coeffs;
        if (temp % 2 == 0) {
            coeffs[1] += temp;
        }
        a1 = coeffs[1];
        coeffs += 2;
    }
}
