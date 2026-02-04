#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t *frame_data;
extern int i;
extern int channels;
extern int frame_size;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of strided access by channels, reorganize to write all channel samples consecutively
    uint16_t* data = frame_data;
    for (j = 0; j < frame_size; j++) {
        uint16_t base_val = 10000 * ((j / 10 * i) % 2);
        *data = base_val;
        for (k = 1; k < channels; k++) {
            data[k] = base_val * (k + 1);
        }
        data += channels; // Move to next frame's first channel
    }
}
