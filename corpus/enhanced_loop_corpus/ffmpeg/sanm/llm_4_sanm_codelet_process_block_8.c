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
    for (k = 0; k < size; k++) {
        for (t = 0; t < size; t++) {
            if (*pglyph) {
                dst[t + k * stride] = colors[1];
                pglyph++;
            } else {
                dst[t + k * stride] = colors[0];
                pglyph++;
            }
        }
    }
}
