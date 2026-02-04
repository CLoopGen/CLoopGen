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
        if (a3 < a4 || i % 2 == 0) {
            a3 += *coeffs;
            a4 += a3;
            if (i > 10) {
                a5 += a4;
                *coeffs = a5;
            } else {
                *coeffs = a4;
            }
        } else {
            a3 += 2 * (*coeffs);
            *coeffs = a3;
        }
        coeffs++;
    }
}
