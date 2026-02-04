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
    // Variant 2: Consecutive reverse traversal
    // Processes array elements from the end towards the beginning
    for (i = header_size - 1; i >= 1; i--)
        header_buffer[i - 1] = buf[i] ^ buf[i + 1];
}
