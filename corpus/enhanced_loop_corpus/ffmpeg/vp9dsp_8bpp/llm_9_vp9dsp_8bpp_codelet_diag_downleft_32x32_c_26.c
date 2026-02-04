#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *top;
extern int i;
extern uint8_t v[31];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 16; i++) {
        uint8_t temp1 = top[i * 2] + top[i * 2 + 1];
        uint8_t temp2 = top[i * 2 + 2];
        v[i] = (temp1 + temp2 + 1) >> 1;
    }
}
