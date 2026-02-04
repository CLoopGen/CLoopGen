#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int header_size;
extern uint8_t header_buffer[128];
extern  uint8_t *buf;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t prev_xor = buf[1] ^ buf[2];
    for (i = 1; i < header_size; i++) {
        uint8_t current_xor = buf[i] ^ buf[i + 1];
        header_buffer[i - 1] = prev_xor;
        prev_xor = current_xor;
    }
}
