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
    unsigned int local_a1 = a1;
    for (i = 0; i < length - 1 >> 1; i++) {
        *coeffs += local_a1;
        local_a1 = (unsigned int)coeffs[1] + (unsigned int)*coeffs;
        coeffs[1] = local_a1;
        coeffs += 2;
    }
    a1 = local_a1;
}
