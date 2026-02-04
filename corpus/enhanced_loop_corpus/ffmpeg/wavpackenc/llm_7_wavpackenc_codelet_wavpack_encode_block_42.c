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
    uint32_t local_crc = crc;
    for (i = 0; i < nb_samples; i += 2) {
        if (i + 1 < nb_samples) {
            uint32_t update1 = (local_crc << 3) + ((uint32_t)samples_l[i] << 1) + samples_l[i] + samples_r[i];
            uint32_t update2 = ((local_crc + update1) << 3) + ((uint32_t)samples_l[i+1] << 1) + samples_l[i+1] + samples_r[i+1];
            local_crc += update1 + update2;
        } else {
            local_crc += (local_crc << 3) + ((uint32_t)samples_l[i] << 1) + samples_l[i] + samples_r[i];
        }
    }
    crc = local_crc;
}
