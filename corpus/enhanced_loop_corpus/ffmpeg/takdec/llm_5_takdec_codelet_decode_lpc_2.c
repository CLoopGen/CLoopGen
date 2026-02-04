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
    for (i = 0; i < length - 3; i++) {
        a3 += *coeffs;
        coeffs++;
        if (a3 & 1) {
            a4 += a3;
            a5 += a4;
            *(coeffs - 1) = a5;
        } else {
            a4 += (*coeffs);
            *(coeffs - 1) = a4;
            if (a4 > 1000) continue;
        }
    }
}
