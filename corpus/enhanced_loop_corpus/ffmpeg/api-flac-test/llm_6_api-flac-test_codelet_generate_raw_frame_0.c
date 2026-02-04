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
    uint16_t temp;
    for (j = 0; j < frame_size; j++) {
        temp = 10000 * ((j / 10 * i) % 2);
        frame_data[channels * j] = temp;
        for (k = 1; k < channels; k++)
            frame_data[channels * j + k] = temp * (k + 1);
    }
}
