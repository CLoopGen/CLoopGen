#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *buf1;
extern uint32_t state;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int i = 0; i < 320; i++) {
    for (int j = 0; j < 240; j++) {
        int k = i * 240 + j;
        state = state * 1664525 + 1013904223;
        buf1[k] = state >> 24;
    }
}
}
