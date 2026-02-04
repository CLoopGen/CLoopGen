#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int bytes;
extern int i;
extern uint32_t c;
extern  uint32_t *buf;
extern uint32_t *output;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t c1 = c ^ 0x12345678U;
    uint32_t c2 = c ^ 0x87654321U;
    for (i = 0; i < bytes / 4; i++) {
        output[i] = (c ^ buf[i]) + (c1 ^ buf[i]) - (c2 & buf[i]);
    }
}
