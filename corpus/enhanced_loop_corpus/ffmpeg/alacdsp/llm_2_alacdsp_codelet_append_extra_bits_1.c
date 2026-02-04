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
    // Variant 1: Strided memory access with increased stride of 2 (unrolled-like pattern)
    // Access every second element in a strided manner, then handle remainder
    for (ch = 0; ch < channels; ch++) {
        int stride = 2;
        // Process elements with stride
        for (i = 0; i + 1 < nb_samples; i += stride) {
            buffer[ch][i]     = ((unsigned int)buffer[ch][i]     << extra_bits) | extra_bits_buffer[ch][i];
            buffer[ch][i + 1] = ((unsigned int)buffer[ch][i + 1] << extra_bits) | extra_bits_buffer[ch][i + 1];
        }
        // Handle leftover sample if nb_samples is odd
        if (i < nb_samples) {
            buffer[ch][i] = ((unsigned int)buffer[ch][i] << extra_bits) | extra_bits_buffer[ch][i];
        }
    }
}
