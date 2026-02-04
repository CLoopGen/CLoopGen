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
    short local_crossings[256];
    ssize_t local_parity = parity;

    for (i = 0; i <= 255; i++) {
        local_crossings[i] = 0;
        if (i > 0) {
            if (second_derivative[i] < 0. && local_parity > 0)
                local_crossings[i] = (-1);
            else if (second_derivative[i] > 0. && local_parity < 0)
                local_crossings[i] = 1;
        }

        if (second_derivative[i] < 0.)
            local_parity = 1;
        else if (second_derivative[i] > 0.)
            local_parity = (-1);
    }

    for (i = 0; i <= 255; i++) {
        crossings[i] = local_crossings[i];
    }
    parity = local_parity;
}
