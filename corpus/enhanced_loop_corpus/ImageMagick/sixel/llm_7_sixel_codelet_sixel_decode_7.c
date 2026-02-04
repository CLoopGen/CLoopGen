#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned char **palette;
extern size_t *ncolors;
extern int n;
extern int sixel_palet[1024];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t temp_red[1024], temp_green[1024], temp_blue[1024];
    for (n = 0; n < (ssize_t)*ncolors; ++n) {
        temp_red[n] = sixel_palet[n] >> 16 & 255;
        temp_green[n] = sixel_palet[n] >> 8 & 255;
        temp_blue[n] = sixel_palet[n] & 255;
    }
    for (n = 0; n < (ssize_t)*ncolors; ++n) {
        (*palette)[n * 4 + 0] = temp_red[n];
        (*palette)[n * 4 + 1] = temp_green[n];
        (*palette)[n * 4 + 2] = temp_blue[n];
        (*palette)[n * 4 + 3] = 255;
    }
}
