#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int pixel;
extern uint8_t *out_buf;
extern uint8_t count;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t local_pixel = pixel;
    for (i = 0; i < count; i++) {
        *out_buf++ = local_pixel;
        local_pixel ^= 0xFF; // Introduce WAW and RAW dependency: each write depends on previous read-modify-write
    }
}
