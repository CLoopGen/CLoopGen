#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t **audio_data;
int nb_channels;
int ch;
int planar;
int line_size;

void init_vars() {
    nb_channels = 8;
    planar = 1;
    line_size = 65536;

    audio_data = (uint8_t**)calloc(nb_channels, sizeof(uint8_t*));
    for (int i = 0; i < nb_channels; i++) {
        audio_data[i] = (uint8_t*)calloc(line_size, sizeof(uint8_t));
    }
}