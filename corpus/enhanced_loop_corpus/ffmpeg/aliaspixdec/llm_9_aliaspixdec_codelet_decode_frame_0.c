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
    int stride = 3;
    for (i = 0; i < count; i++) {
        uint8_t val0 = (pixel >> 16);
        uint8_t val1 = (pixel >> 8);
        uint8_t val2 = pixel;

        out_buf[i * stride + 0] = val0;
        out_buf[i * stride + 1] = val1;
        out_buf[i * stride + 2] = val2;
    }
    out_buf += count * 3;
}
