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
    size_t temp_len = 0;
    for (i = 0; i < length_code_size && i < 4; i++) {
        temp_len = (temp_len * 256) + size_buf[i];
    }
    box_len = temp_len;
}
