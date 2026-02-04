#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int palette_scale;
extern unsigned char palette_buffer[768];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 1 + (palette_buffer[0] & 1);
    for (i = 0; i < 768; i += step) {
        if (palette_buffer[i] * 2 > 127) {
            palette_scale = 0;
            break;
        }
    }
}
