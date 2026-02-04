#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int palette_scale;
extern unsigned char palette_buffer[768];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    palette_scale = 0;
    for (i = 0; i < 768 && palette_buffer[i] <= 63; i++);
}
