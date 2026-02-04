#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *top;
extern int i;
extern uint8_t v[31];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 32 - 4; i += 2) {
        v[i]   = (top[i] + top[i + 1] * 3 + top[i + 2] * 2 + top[i + 3] + 4) >> 3;
        v[i+1] = (top[i+1] + top[i + 2] * 3 + top[i + 3] * 2 + top[i + 4] + 4) >> 3;
    }
}
