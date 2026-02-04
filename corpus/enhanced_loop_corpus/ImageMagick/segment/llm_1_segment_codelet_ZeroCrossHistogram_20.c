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
    for (ssize_t outer = 0; outer < 16; outer++) {
        for (ssize_t inner = 0; inner < 16; inner++) {
            i = outer * 16 + inner;
            if (i > 255) continue;
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
}
