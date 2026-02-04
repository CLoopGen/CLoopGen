#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int palette_scale;
extern unsigned char palette_buffer[768];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (j = 0; j < 768; j++) {
        i = j;
        if (palette_buffer[i] > 63) {
            palette_scale = 0;
            break;
        }
    }
}
