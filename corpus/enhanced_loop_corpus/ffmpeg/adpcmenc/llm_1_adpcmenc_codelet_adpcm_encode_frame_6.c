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
    for (i = 0; i < n; i += 4) {
        if (i + 1 < n) {
            *dst++ = buf[i] | (buf[i + 1] << 4);
        }
        if (i + 3 < n) {
            *dst++ = buf[i + 2] | (buf[i + 3] << 4);
        }
    }
}
