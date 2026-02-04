#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int stride;
extern int size;
extern int k;
extern int t;
extern uint8_t colors[2];
extern int8_t *pglyph;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int index = 0;
    for (k = 0; k < size; k++) {
        for (t = 0; t < size; t++) {
            int offset = t + k * stride;
            dst[offset] = colors[(*(pglyph + index)) & 1];
            index++;
        }
    }
}
