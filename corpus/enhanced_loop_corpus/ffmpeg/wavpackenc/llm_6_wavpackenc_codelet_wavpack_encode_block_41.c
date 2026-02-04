#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *samples_l;
extern int i;
extern int nb_samples;
extern uint32_t crc;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    uint32_t temp_crc = crc;
    for (i = 0; i < nb_samples; i++) {
        temp_crc += (temp_crc << 1) + samples_l[i];
    }
    crc = temp_crc;
}
