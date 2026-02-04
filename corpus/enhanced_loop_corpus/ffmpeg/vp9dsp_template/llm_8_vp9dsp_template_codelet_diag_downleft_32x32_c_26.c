#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *top;
extern int i;
extern uint8_t v[31];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 31; i += 2) {
        v[i] = (top[i] + top[i + 1] * 3 + 4) >> 2;
        if (i + 1 < 31) {
            v[i + 1] = (top[i + 1] + top[i + 2] * 3 + 4) >> 2;
        }
    }
}
