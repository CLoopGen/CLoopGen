#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *buf2;
extern uint32_t state;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 640; j++) {
            for (int k_inner = 0; k_inner < 30; k_inner++) {
                int k = (i * 640 * 30) + (j * 30) + k_inner;
                if (k >= 640 * 480) break;
                state = state * 1664525 + 1013904223;
                buf2[k] = state >> 24;
            }
        }
    }
}
