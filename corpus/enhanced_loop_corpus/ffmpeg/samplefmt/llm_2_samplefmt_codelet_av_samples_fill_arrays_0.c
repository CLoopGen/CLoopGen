#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t **audio_data;
extern int nb_channels;
extern int ch;
extern int planar;
extern int line_size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with increased stride (simulating wider data layout)
    // Instead of accessing line_size bytes apart, we access at multiples of line_size for a strided pattern.
    int stride_factor = 2; // Simulate a strided layout where each channel is spaced further
    for (ch = 1; planar && ch < nb_channels; ch++) {
        audio_data[ch] = audio_data[0] + ch * (line_size * stride_factor);
    }
}
