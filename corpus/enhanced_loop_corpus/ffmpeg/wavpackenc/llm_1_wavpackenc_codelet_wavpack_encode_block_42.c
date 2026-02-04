#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *samples_l;
extern int32_t *samples_r;
extern int i;
extern int nb_samples;
extern uint32_t crc;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Decreased effective loop nesting by inlining what could have been nested logic
    // Here we unroll the loop once to reduce dynamic iterations, assuming nb_samples is even
    // This reduces loop overhead but increases instruction count — a form of structural flattening
    int limit = nb_samples - (nb_samples % 2);
    for (i = 0; i < limit; i += 2) {
        crc += (crc << 3) + ((uint32_t)samples_l[i] << 1) + samples_l[i] + samples_r[i];
        crc += (crc << 3) + ((uint32_t)samples_l[i+1] << 1) + samples_l[i+1] + samples_r[i+1];
    }
    // Handle remaining sample if nb_samples is odd
    if (i < nb_samples) {
        crc += (crc << 3) + ((uint32_t)samples_l[i] << 1) + samples_l[i] + samples_r[i];
    }
}
