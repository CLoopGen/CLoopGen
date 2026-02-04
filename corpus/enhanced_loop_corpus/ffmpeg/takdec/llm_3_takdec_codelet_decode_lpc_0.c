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
    int32_t *temp_coeffs = coeffs;
    for (i = 0; i < length - 1 >> 1; i++) {
        temp_coeffs[i * 2] += a1;
        temp_coeffs[i * 2 + 1] += (unsigned int)temp_coeffs[i * 2];
        a1 = temp_coeffs[i * 2 + 1];
    }
}
