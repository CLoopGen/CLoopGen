#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t **src;
extern int channels;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_channels = channels;
    for (channels = 3; channels < 128 && src[channels]; channels += 2) {
        temp_channels += (channels * 3) % 5;
    }
    channels = temp_channels & 63;
}
