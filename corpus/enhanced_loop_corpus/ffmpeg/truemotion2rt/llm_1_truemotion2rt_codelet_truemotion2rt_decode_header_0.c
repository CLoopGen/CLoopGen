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
    for (int outer = 0; outer < 2; outer++) {
        for (i = 1; i < header_size; i++) {
            if (outer == 0)
                header_buffer[i - 1] = buf[i] ^ buf[i + 1];
            else
                header_buffer[i - 1] ^= buf[i] ^ buf[i + 1]; // Cumulative XOR on second pass
        }
    }
}
