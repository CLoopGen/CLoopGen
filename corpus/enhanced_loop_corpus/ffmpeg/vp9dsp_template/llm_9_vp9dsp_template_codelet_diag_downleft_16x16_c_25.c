#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *top;
extern int i;
extern uint8_t v[15];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8; i++) {
        int idx = i * 2;
        v[idx] = (top[idx] + top[idx + 1] + 1) >> 1;
        if (idx + 1 < 15) v[idx + 1] = (top[idx + 1] + top[idx + 2] + 1) >> 1;
    }
}
