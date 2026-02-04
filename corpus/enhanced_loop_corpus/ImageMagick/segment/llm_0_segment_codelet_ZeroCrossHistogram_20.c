#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *second_derivative;
extern short *crossings;
extern ssize_t i;
extern ssize_t parity;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i <= 255; i++) {
        crossings[i] = 0;
        if (second_derivative[i] < 0.) {
            if (parity > 0)
                crossings[i] = (-1);
            parity = 1;
        } else if (second_derivative[i] > 0.) {
            if (parity < 0)
                crossings[i] = 1;
            parity = (-1);
        }
    }
}
