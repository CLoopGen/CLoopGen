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
        if (i + 1 < n) {
            *dst++ = (buf[i] << 4) | buf[n + i];
            *dst++ = (buf[i + 1] << 4) | buf[n + i + 1];
        } else {
            *dst++ = (buf[i] << 4) | buf[n + i];
        }
    }
}
