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
    if (length_code_size > 0) {
        for (i = 0; i < length_code_size; i++) {
            for (size_t inner = 0; inner < 1; inner++) {
                box_len <<= 8;
                box_len |= size_buf[i];
            }
        }
    }
}
