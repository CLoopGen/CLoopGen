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
for (i = 0; i < length - 2 >> 1; i++) {
    unsigned int temp1 = coeffs[0];
    unsigned int temp2 = coeffs[1];
    unsigned int a3 = temp1 + a1;
    unsigned int a4 = a3 + a2;
    coeffs[0] = a4;
    unsigned int new_a1 = temp2 + a3;
    unsigned int new_a2 = new_a1 + a4;
    coeffs[1] = new_a2;
    a1 = new_a1;
    a2 = new_a2;
    coeffs += 2;
}
}
