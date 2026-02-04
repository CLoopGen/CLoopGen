#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *top;
extern int i;
extern uint8_t v[7];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8 - 1; i += 2) {
        uint8_t val1 = top[i] + (top[i + 1] << 1) + 2;
        v[i] = val1 >> 2;
        if (i + 1 < 6) {
            uint8_t val2 = top[i + 1] + (top[i + 2] << 1) + 2;
            v[i + 1] = val2 >> 2;
        }
    }
}
