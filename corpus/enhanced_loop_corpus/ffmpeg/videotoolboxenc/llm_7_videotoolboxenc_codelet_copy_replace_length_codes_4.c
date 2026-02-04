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
    size_t local_box_len = box_len;
    for (i = 0; i < length_code_size; i++) {
        local_box_len <<= 8;
        local_box_len |= size_buf[i];
        box_len = local_box_len; // Introduce WAW dependency: write-after-write on box_len
    }
}
