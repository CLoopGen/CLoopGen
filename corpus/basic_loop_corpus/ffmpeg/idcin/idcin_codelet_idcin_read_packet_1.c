#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int palette_scale;
extern unsigned char palette_buffer[768];

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < 768; i++)
    if (palette_buffer[i] > 63) {
        palette_scale = 0;
        break;
    }

}
