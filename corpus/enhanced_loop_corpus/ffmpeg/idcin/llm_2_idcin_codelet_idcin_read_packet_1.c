#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int palette_scale;
extern unsigned char palette_buffer[768];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 4
    for (i = 0; i < 768; i += 4) {
        if (palette_buffer[i] > 63) {
            palette_scale = 0;
            break;
        }
        // Check remaining elements in stride group if within bounds
        if ((i + 1) < 768 && palette_buffer[i + 1] > 63) {
            palette_scale = 0;
            break;
        }
        if ((i + 2) < 768 && palette_buffer[i + 2] > 63) {
            palette_scale = 0;
            break;
        }
        if ((i + 3) < 768 && palette_buffer[i + 3] > 63) {
            palette_scale = 0;
            break;
        }
    }
}
