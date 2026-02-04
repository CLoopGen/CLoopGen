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
    for (i = 0; i < n; i += 2) {
        uint8_t val = 0;
        if (i + 1 < n) {
            val = buf[i] | (buf[i + 1] << 4);
        } else {
            val = buf[i];
        }
        *dst++ = val;
    }
}
