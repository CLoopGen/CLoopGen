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
    for (ch = 0; ch < channels; ch++) {
        int32_t* buf_ch = buffer[ch];
        int32_t* extra_ch = extra_bits_buffer[ch];
        for (i = 0; i < nb_samples; i += 2) {
            // Unroll loop: process two iterations at once to increase computational intensity
            if (i + 1 < nb_samples) {
                uint32_t val1 = ((unsigned int)buf_ch[i] << extra_bits) | extra_ch[i];
                uint32_t val2 = ((unsigned int)buf_ch[i+1] << extra_bits) | extra_ch[i+1];
                buf_ch[i] = val1;
                buf_ch[i+1] = val2;
            } else {
                buf_ch[i] = ((unsigned int)buf_ch[i] << extra_bits) | extra_ch[i];
            }
        }
    }
}
