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
        double sd = second_derivative[i];
        int neg = (sd < 0.);
        int pos = (sd > 0.);
        if (neg || pos) {
            if (neg && parity > 0)
                crossings[i] = -1;
            else if (pos && parity < 0)
                crossings[i] = 1;
            parity = neg ? 1 : -1;
        }
    }
}
