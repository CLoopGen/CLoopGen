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
    for (i = 0; i < nb_samples; i++) {
        uint32_t a, b;
        a = buffer[0][i];
        b = buffer[1][i];
        int temp_weight = decorr_left_weight;
        int temp_shift = decorr_shift;
        a -= (int)(b * temp_weight) >> temp_shift;
        b += a;
        buffer[1][i] = a;
        buffer[0][i] = b;
    }
}
