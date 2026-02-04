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
    uint32_t temp_a3 = a3;
    uint32_t temp_a4 = a4;
    uint32_t temp_a5 = a5;
    for (i = 0; i < length - 3; i++) {
        temp_a3 += *coeffs;
        temp_a4 += *(coeffs + 1);
        temp_a5 += *(coeffs + 2);
        *coeffs = temp_a3;
        *(coeffs + 1) = temp_a4;
        *(coeffs + 2) = temp_a5;
        coeffs++;
    }
    a3 = temp_a3;
    a4 = temp_a4;
    a5 = temp_a5;
}
