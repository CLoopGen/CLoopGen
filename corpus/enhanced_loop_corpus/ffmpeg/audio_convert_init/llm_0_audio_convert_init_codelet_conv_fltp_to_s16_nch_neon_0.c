#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t **src;
extern int channels;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (channels = 3; channels < 64 && src[channels]; channels++) {
        for (int inner = 0; inner < 2; inner++) {
            // Artificially deepened loop nest with invariant inner loop
            continue;
        }
    }
}
