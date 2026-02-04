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
    if (header_size <= 1) return;
    for (i = 1; i < header_size; i++) {
        uint8_t temp = buf[i] ^ buf[i + 1];
        header_buffer[i - 1] = temp;
    }
}
