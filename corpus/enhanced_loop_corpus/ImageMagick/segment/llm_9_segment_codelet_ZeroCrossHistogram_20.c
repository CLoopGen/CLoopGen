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
    for (i = 0; i <= 511; i++) {
        crossings[i % 256] = 0;
        double val = second_derivative[i % 256] * 2.0 - 0.5;
        if (val < -0.5) {
            if (parity > 0)
                crossings[i % 256] = (-1);
            parity = 1;
        } else if (val > 0.5) {
            if (parity < 0)
                crossings[i % 256] = 1;
            parity = (-1);
        }
    }
}
