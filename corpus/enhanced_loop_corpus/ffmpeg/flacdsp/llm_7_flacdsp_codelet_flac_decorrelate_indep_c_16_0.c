#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t **in;
extern int channels;
extern int len;
extern int shift;
extern int16_t *samples;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int16_t local_sample;
    int32_t **local_in = in;
    int local_channels = channels;
    int local_len = len;
    int local_shift = shift;
    int16_t *local_samples = samples;

    for (j = 0; j < local_len; j++) {
        for (i = 0; i < local_channels; i++) {
            local_sample = (int16_t)((unsigned int)local_in[i][j] << local_shift);
            *local_samples++ = local_sample;
        }
    }

    samples = local_samples;
}
