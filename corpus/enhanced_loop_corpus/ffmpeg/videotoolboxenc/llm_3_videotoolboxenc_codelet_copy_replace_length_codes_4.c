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
    for (i = 0; i < length_code_size; i += 1) {
        size_t idx = (i * 3) % length_code_size; // Indirect, strided access using modulo to stay in bounds
        temp_len <<= 8;
        temp_len |= size_buf[idx];
    }
    box_len = temp_len;
}
