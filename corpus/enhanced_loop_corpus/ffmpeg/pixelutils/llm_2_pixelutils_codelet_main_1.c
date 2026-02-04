#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *buf1;
extern uint32_t state;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 0; k < 320 * 240; k += 4) {
        state = state * 1664525 + 1013904223;
        buf1[k] = state >> 24;
        if (k + 1 < 320 * 240) {
            uint32_t s1 = state * 1664525 + 1013904223;
            buf1[k + 1] = s1 >> 24;
            state = s1;
        }
        if (k + 2 < 320 * 240) {
            uint32_t s2 = state * 1664525 + 1013904223;
            buf1[k + 2] = s2 >> 24;
            state = s2;
        }
        if (k + 3 < 320 * 240) {
            uint32_t s3 = state * 1664525 + 1013904223;
            buf1[k + 3] = s3 >> 24;
            state = s3;
        }
    }
}
