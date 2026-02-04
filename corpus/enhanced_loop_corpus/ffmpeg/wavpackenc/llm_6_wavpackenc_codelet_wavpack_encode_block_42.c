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
    uint32_t temp_crc = crc;
    for (i = 0; i < nb_samples; i++) {
        temp_crc += (temp_crc << 3) + ((uint32_t)samples_l[i] << 1) + samples_l[i] + samples_r[i];
    }
    crc = temp_crc;
}
