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
        uint8_t val = buf[i];
        uint8_t offset_val = buf[n + i];
        if ((val & 0x8) && i < n/2 + n%2) {
            *dst++ = (val << 4) | (offset_val ^ 0xF);
        } else {
            *dst++ = (val << 4) | offset_val;
        }
    }
}
