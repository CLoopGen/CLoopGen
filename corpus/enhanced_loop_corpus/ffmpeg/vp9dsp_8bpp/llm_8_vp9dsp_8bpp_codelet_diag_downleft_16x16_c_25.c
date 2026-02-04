#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *top;
extern int i;
extern uint8_t v[15];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 16 - 3; i += 2) {
        uint8_t a = top[i];
        uint8_t b = top[i + 1];
        uint8_t c = top[i + 2];
        uint8_t d = top[i + 3];
        v[i]     = (a + b * 3 + c * 2 + 2) / 6;
        if (i + 1 < 16 - 3) v[i + 1] = (b + c * 3 + d * 2 + 2) / 6;
    }
}
