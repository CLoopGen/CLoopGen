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
    int i;
    for (i = 1; planar && i < nb_channels; i++) {
        audio_data[i] = audio_data[i - 1] + line_size;
        ch = i; // Update ch after assignment, introducing WAW-like dependency on ch
    }
}
