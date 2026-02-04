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
    for (int j = 0; j < n / 2; j++) {
        i = j * 2;
        *dst++ = buf[i] | (buf[i + 1] << 4);
    }
}
