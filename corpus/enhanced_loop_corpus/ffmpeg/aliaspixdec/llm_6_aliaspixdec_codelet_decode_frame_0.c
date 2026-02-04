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
    int p = pixel;
    for (i = 0; i < count; i++) {
        buf[0] = p >> 16;
        buf[1] = p >> 8;
        buf[2] = p;
        buf += 3;
    }
    out_buf = buf;
}
