#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *coeffs;
extern int length;
extern int i;
extern unsigned int a1;
extern unsigned int a2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < length - 2 >> 2; i++) {
    unsigned int a3 = *coeffs + a1;
    unsigned int a4 = a3 + a2;
    *coeffs = a4;
    a1 = coeffs[1] + a3;
    a2 = a1 + a4;
    coeffs[1] = a2;
    coeffs += 2;
}
}
