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
    for (j = 0; j < frame_size; j++) {
        int base_val = 10000 * ((j / 10 * i) % 2);
        frame_data[channels * j] = base_val;
        if (base_val != 0) {
            for (k = 1; k < channels; k++)
                frame_data[channels * j + k] = frame_data[channels * j] * (k + 1);
        } else {
            for (k = 1; k < channels; k++)
                frame_data[channels * j + k] = 0;
        }
    }
}
