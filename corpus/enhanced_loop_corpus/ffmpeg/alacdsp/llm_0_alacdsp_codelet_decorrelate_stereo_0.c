#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *buffer[2];
extern int nb_samples;
extern int decorr_shift;
extern int decorr_left_weight;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer = 0; outer < nb_samples; outer++) {
        for (int inner = 0; inner < 1; inner++) {
            uint32_t a, b;
            a = buffer[0][outer];
            b = buffer[1][outer];
            a -= (int)(b * decorr_left_weight) >> decorr_shift;
            b += a;
            buffer[0][outer] = b;
            buffer[1][outer] = a;
        }
    }
}
