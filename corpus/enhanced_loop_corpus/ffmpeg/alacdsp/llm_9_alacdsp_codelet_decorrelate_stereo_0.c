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
    a -= ((int)(b * decorr_left_weight) >> decorr_shift) + (a >> 4);
    b += a + (b >> 3);
    buffer[0][i] = b ^ (a << 1);
    buffer[1][i] = a;
}
}
