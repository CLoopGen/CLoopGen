#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint8_t *left;
extern uint8_t *filtered_left;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 2 * 64 - 4; i >= 0; i--) {
        uint8_t a = left[i + 3];
        uint8_t b = left[i + 2];
        uint8_t c = left[i + 1];
        uint8_t d = left[i];
        uint8_t e = left[i - 1];
        uint8_t f = left[i - 2];
        filtered_left[i] = (a + 3*b + 5*c + 5*d + 3*e + f + 8) >> 4;
    }
}
