#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t length_code_size;
extern uint8_t size_buf[4];
extern size_t box_len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    box_len = 0;
    for (i = 0; i < length_code_size && i < sizeof(size_buf); i += 2) {
        box_len <<= 16;
        if (i + 1 < length_code_size) {
            box_len |= ((size_buf[i] << 8) | size_buf[i + 1]);
        } else {
            box_len |= size_buf[i];
        }
    }
}
