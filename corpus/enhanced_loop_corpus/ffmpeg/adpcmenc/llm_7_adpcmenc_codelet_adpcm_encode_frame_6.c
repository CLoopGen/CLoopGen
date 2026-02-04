#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int n;
extern int i;
extern uint8_t *dst;
extern uint8_t *buf;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t prev = 0;
    for (i = 0; i < n; i += 2) {
        uint8_t current = buf[i] | (buf[i + 1] << 4);
        *dst++ = current ^ prev;
        prev = current;
    }
}
