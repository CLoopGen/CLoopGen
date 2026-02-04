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
    for (i = 0; i < nb_samples; i += 2) {
        crc += (crc << 3) + ((uint32_t)samples_l[i] << 1) + samples_l[i] + samples_r[i];
        if (i + 1 < nb_samples) {
            crc += (crc << 2) + ((uint32_t)samples_l[i+1] << 1) + samples_l[i+1] + samples_r[i+1];
        }
    }
}
