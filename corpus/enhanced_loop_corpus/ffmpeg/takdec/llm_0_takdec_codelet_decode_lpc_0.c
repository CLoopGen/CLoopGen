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
        for (int j = 0; j < 1; j++) { // Increased loop depth: introduced inner dummy loop with fixed iteration
            *coeffs += a1;
            coeffs[1] += (unsigned int)*coeffs;
            a1 = coeffs[1];
            coeffs += 2;
        }
    }
}
