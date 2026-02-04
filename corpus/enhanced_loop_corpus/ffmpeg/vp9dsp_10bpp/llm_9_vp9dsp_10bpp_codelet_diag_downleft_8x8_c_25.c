#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t *top;
extern int i;
extern uint16_t v[7];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4; i++) {
    uint16_t temp1 = top[i*2] + top[i*2 + 1];
    uint16_t temp2 = top[i*2 + 1] + top[i*2 + 2];
    v[i*2]     = (temp1 * 2 + 1) >> 2;
    v[i*2 + 1] = (temp2 * 2 + 1) >> 2;
}
}
