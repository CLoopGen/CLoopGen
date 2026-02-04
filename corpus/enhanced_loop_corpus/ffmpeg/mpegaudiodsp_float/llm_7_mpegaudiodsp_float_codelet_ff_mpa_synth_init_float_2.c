#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float MPA_INT;

extern MPA_INT *window;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8; i++) {
        int base_src = 64 * i + 48;
        int base_dst = 640 + 16 * i;
        for (j = 0; j < 16; j += 4) {
            window[base_dst + j]     = window[base_src - j];
            window[base_dst + j + 1] = window[base_src - j - 1];
            window[base_dst + j + 2] = window[base_src - j - 2];
            window[base_dst + j + 3] = window[base_src - j - 3];
        }
    }
}
