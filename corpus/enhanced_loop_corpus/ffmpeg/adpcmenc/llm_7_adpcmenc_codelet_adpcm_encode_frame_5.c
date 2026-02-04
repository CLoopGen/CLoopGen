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
    uint8_t *local_dst = dst;
    for (i = 0; i < n; i++) {
        local_dst[i] = (buf[i] << 4) | buf[n + i];
    }
    dst += n;
}
