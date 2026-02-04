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
    for (i = 0; i < count; i++) {
        for (int j = 0; j < 1; j++) {
            ((uint8_t *)(out_buf))[2] = (pixel);
            ((uint8_t *)(out_buf))[1] = (pixel) >> 8;
            ((uint8_t *)(out_buf))[0] = (pixel) >> 16;
        }
        out_buf += 3;
    }
}
