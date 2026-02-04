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
    // Variant 2: Consecutive (unrolled by 2) memory access for improved spatial locality
    int limit = nb_samples - 1;
    for (i = 0; i < limit; i += 2) {
        crc += (crc << 3) + ((uint32_t)samples_l[i] << 1) + samples_l[i] + samples_r[i];
        crc += (crc << 3) + ((uint32_t)samples_l[i+1] << 1) + samples_l[i+1] + samples_r[i+1];
    }
    // Handle remaining element if nb_samples is odd
    if (i < nb_samples) {
        crc += (crc << 3) + ((uint32_t)samples_l[i] << 1) + samples_l[i] + samples_r[i];
    }
}
