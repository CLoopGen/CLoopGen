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
    for (i = 0; i < count * 2; i += 2) {
        uint32_t p = pixel;
        ((uint8_t *)(out_buf))[0] = (p >> 16) & 0xFF;
        ((uint8_t *)(out_buf))[1] = (p >> 8) & 0xFF;
        ((uint8_t *)(out_buf))[2] = p & 0xFF;
        out_buf += 3;

        if (i + 1 < count * 2) {
            ((uint8_t *)(out_buf))[0] = (p >> 16) & 0xFF;
            ((uint8_t *)(out_buf))[1] = (p >> 8) & 0xFF;
            ((uint8_t *)(out_buf))[2] = p & 0xFF;
            out_buf += 3;
        }
    }
}
