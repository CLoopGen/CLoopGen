#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *t1;
extern int half_size;
extern  uint8_t *t2;
extern uint8_t *s;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 4;
    for (i = 0; i < half_size; i += step / 2) {
        // Unroll by factor of 2: process two iterations per loop cycle
        if (i + 0 < half_size) {
            *(s++) = *(t1++);
            *(s++) = *(t2++);
        }
        if (i + 1 < half_size) {
            *(s++) = *(t1++);
            *(s++) = *(t2++);
        }
    }
}
