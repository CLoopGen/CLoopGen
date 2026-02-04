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
    for (i = 0; i < n; i++) {
        if ((buf[i] & 0xF0) == 0) {
            *dst++ = buf[n + i] << 4;
        } else {
            *dst++ = buf[i] | (buf[n + i] << 4);
        }
    }
}
