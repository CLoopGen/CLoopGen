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
    int temp_ch;
    uint8_t *prev_ptr;
    for (ch = 1; planar && ch < nb_channels; ch++) {
        temp_ch = ch - 1;
        prev_ptr = audio_data[temp_ch] + line_size;
        audio_data[ch] = prev_ptr;
    }
}
