#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *gamma;
extern ssize_t x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ssize_t i = 0; i <= 15; i++) {
    for (ssize_t j = 0; j <= 15; j++) {
        ssize_t index = (i << 4) | j;
        if (index <= 255)
            gamma[index] = 0.;
    }
}
}
