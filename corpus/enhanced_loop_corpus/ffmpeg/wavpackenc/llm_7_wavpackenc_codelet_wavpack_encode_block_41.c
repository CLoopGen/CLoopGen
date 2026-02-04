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
    uint32_t local_crc = crc;
    for (i = 0; i < nb_samples; i += 2) {
        if (i + 1 < nb_samples) {
            local_crc += (local_crc << 1) + samples_l[i];
            local_crc += (local_crc << 1) + samples_l[i + 1];
        } else {
            local_crc += (local_crc << 1) + samples_l[i];
        }
    }
    crc = local_crc;
}
