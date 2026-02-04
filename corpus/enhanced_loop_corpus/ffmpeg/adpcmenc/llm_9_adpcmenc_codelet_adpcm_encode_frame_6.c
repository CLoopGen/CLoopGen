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
for (i = 0; i < n - 1; i++) {
    uint8_t val1 = buf[i] & 0xF;
    uint8_t val2 = buf[i + 1] & 0xF;
    *dst++ = val1 | (val2 << 4);
    i++; 
}
}
