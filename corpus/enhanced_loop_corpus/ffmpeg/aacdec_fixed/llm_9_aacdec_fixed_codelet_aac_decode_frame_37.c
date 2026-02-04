#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern int buf_size;
extern int buf_consumed;
extern int buf_offset;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (buf_offset = buf_consumed; buf_offset < buf_size; buf_offset++) {
        // Increase computational work per iteration with additional arithmetic
        uint8_t val = buf[buf_offset] & 0xF;
        val ^= (buf_offset * 37) % 251;
        if (val == 0xFF) {
            break;
        }
    }
}
