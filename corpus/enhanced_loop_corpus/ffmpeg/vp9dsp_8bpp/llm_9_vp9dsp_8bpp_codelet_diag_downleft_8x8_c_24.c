#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *top;
extern int i;
extern uint8_t v[7];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 4; i++) {
        uint8_t temp1 = top[i] + top[i + 1];
        uint8_t temp2 = top[i + 2] + top[i + 3];
        v[i * 2]     = (temp1 * 2 + temp2 + 2) >> 2;
        v[i * 2 + 1] = (temp1 + temp2 * 2 + 2) >> 2;
    }
}
