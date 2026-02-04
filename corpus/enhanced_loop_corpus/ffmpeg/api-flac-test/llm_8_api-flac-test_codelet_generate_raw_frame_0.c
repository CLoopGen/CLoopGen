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
    for (j = 0; j < frame_size; j += 2) {
        uint16_t base_val = 5000 * ((j / 5 * i) % 3);
        frame_data[channels * j] = base_val;
        if (j + 1 < frame_size) {
            frame_data[channels * (j + 1)] = 5000 * (((j + 1) / 5 * i) % 3);
        }
        for (k = 1; k < channels; k++) {
            frame_data[channels * j + k] = base_val * (k * 2);
            if (j + 1 < frame_size) {
                frame_data[channels * (j + 1) + k] = frame_data[channels * (j + 1)] * (k * 2);
            }
        }
    }
}
