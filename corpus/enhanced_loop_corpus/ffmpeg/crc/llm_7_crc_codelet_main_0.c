#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t buf[1999];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t prev = 0;
    for (i = 0; i < sizeof(buf); i++) {
        buf[i] = i + i * i + prev;
        prev = buf[i] & 0xFF;
    }
}
