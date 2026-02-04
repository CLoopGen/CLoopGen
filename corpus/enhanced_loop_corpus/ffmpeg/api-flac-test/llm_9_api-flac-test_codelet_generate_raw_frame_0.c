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
    int step = (i > 0) ? i : 1;
    for (j = 0; j < frame_size; j++) {
        uint16_t temp = 8000 * ((j * i) % 4 == 0);
        frame_data[channels * j] = temp;
        for (k = 1; k < channels; k += 2) {
            uint16_t val = temp * (k + 1);
            frame_data[channels * j + k] = val;
            if (k + 1 < channels) {
                frame_data[channels * j + k + 1] = val * 2;
            }
        }
    }
}
