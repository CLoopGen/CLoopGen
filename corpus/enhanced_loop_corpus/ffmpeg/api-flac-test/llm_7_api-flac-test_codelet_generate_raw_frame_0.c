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
    uint16_t base_val;
    for (j = 0; j < frame_size; j++) {
        base_val = 10000 * ((j / 10 * i) % 2);
        for (k = 0; k < channels; k++) {
            if (k == 0)
                frame_data[channels * j + k] = base_val;
            else
                frame_data[channels * j + k] = base_val * (k + 1);
        }
    }
}
