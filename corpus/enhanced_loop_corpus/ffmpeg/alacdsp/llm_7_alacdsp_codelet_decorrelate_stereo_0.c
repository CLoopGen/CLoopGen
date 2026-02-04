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
        uint32_t a0, b0, a1, b1;
        if (i + 1 < nb_samples) {
            a0 = buffer[0][i];
            b0 = buffer[1][i];
            a1 = buffer[0][i + 1];
            b1 = buffer[1][i + 1];
            a0 -= (int)(b0 * decorr_left_weight) >> decorr_shift;
            b0 += a0;
            a1 -= (int)(b1 * decorr_left_weight) >> decorr_shift;
            b1 += a1;
            buffer[0][i] = b0;
            buffer[1][i] = a0;
            buffer[0][i + 1] = b1;
            buffer[1][i + 1] = a1;
            i++;
        } else {
            a0 = buffer[0][i];
            b0 = buffer[1][i];
            a0 -= (int)(b0 * decorr_left_weight) >> decorr_shift;
            b0 += a0;
            buffer[0][i] = b0;
            buffer[1][i] = a0;
        }
    }
}
