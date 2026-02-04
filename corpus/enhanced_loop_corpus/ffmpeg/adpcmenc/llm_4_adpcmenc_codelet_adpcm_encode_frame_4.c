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
    i = 0;
    while (i < n - 1) {
        *dst++ = (buf[i] << 4) | buf[i + 1];
        i += 2;
    }
}
