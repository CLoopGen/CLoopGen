#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t **src;
extern int channels;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_channels = channels;
    for (channels = 3; temp_channels < 64 && src[temp_channels]; temp_channels++)
        ;
    channels = temp_channels;
}
