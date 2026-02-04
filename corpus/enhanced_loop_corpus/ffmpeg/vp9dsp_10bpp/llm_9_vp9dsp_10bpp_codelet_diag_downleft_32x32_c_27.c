#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t *top;
extern int i;
extern uint16_t v[31];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 16; i++) {
        uint16_t a = top[2*i];
        uint16_t b = top[2*i + 1];
        uint16_t c = top[2*i + 2];
        v[2*i] = (a + b * 2 + c + 2) >> 2;
        if (2*i + 1 < 30) {
            v[2*i + 1] = (b + c * 2 + top[2*i + 3] + 2) >> 2;
        }
    }
}
