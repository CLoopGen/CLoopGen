#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t **src;
extern int channels;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (channels = 3; channels < 64 && src[channels]; ) {
        channels++;
        if (channels >= 64 || !src[channels]) break;
        channels++;
        if (channels >= 64 || !src[channels]) break;
    }
}
