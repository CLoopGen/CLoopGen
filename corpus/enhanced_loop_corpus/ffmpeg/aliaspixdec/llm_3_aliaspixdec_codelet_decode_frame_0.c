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
    uint8_t *buf = out_buf;
    ptrdiff_t stride = 6; // Strided access with step of 6 bytes
    for (i = 0; i < count; i++) {
        buf[2 * stride] = pixel;
        buf[1 * stride] = pixel >> 8;
        buf[0 * stride] = pixel >> 16;
        buf += 3 * stride;
    }
}
