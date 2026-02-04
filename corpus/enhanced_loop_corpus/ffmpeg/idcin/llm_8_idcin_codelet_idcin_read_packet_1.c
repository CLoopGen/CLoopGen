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
    for (i = 0; i < 768; i += 3) {
        for (j = 0; j < 3 && (i + j) < 768; j++) {
            if (palette_buffer[i + j] > 63) {
                palette_scale = 0;
                goto exit_loop;
            }
        }
    }
    exit_loop:;
}
