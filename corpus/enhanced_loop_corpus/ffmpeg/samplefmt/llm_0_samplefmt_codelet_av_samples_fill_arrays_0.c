#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t **audio_data;
extern int nb_channels;
extern int ch;
extern int planar;
extern int line_size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer = 0; outer < 1; outer++) {
        for (ch = 1; planar && ch < nb_channels; ch++)
            audio_data[ch] = audio_data[ch - 1] + line_size;
    }
}
