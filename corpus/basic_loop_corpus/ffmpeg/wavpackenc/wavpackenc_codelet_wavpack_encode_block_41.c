#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *samples_l;
extern int i;
extern int nb_samples;
extern uint32_t crc;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < nb_samples; i++)
    crc += (crc << 1) + samples_l[i];

}
