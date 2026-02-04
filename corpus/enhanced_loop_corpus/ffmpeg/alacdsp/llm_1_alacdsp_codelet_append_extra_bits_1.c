#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *buffer[2];
extern int32_t *extra_bits_buffer[2];
extern int extra_bits;
extern int channels;
extern int nb_samples;
extern int i;
extern int ch;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int idx = 0;
    for (idx = 0; idx < channels * nb_samples; idx++) {
        ch = idx / nb_samples;
        i = idx % nb_samples;
        buffer[ch][i] = ((unsigned int)buffer[ch][i] << extra_bits) | extra_bits_buffer[ch][i];
    }
}
