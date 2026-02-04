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
    // Variant 1: Strided memory access with stride of 2
    // Skips every other element to create a strided access pattern
    for (i = 2; i < header_size; i += 2)
        header_buffer[i - 2] = buf[i] ^ buf[i + 1];
}
