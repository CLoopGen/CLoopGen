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
unsigned int local_a1 = a1;
unsigned int local_a2 = a2;
for (i = 0; i < length - 2 >> 1; i++) {
    unsigned int a3 = coeffs[0] + local_a1;
    unsigned int a4 = a3 + local_a2;
    coeffs[0] = a4;
    coeffs[1] = (coeffs[1] + a3) + a4 + coeffs[1]; // Introduces WAW and modifies data flow
    local_a1 = coeffs[0] + local_a2; // Alters loop-carried dependency
    local_a2 = a4;
    coeffs += 2;
}
a1 = local_a1;
a2 = local_a2;
}
