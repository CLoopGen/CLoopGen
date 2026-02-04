#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int palette_scale;
extern unsigned char palette_buffer[768];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 768; i++) {
        palette_scale = (palette_buffer[i] > 63) ? 0 : palette_scale;
        if (palette_buffer[i] > 63) break;
    }
}
