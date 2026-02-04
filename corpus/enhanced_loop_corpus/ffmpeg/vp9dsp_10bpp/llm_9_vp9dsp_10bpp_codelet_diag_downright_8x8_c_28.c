#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t *top;
extern  uint16_t *left;
extern int i;
extern uint16_t v[15];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4; i++) {
    uint16_t temp1 = (left[2*i] + left[2*i + 2] + 2) >> 2;
    uint16_t temp2 = (top[2*i] + top[2*i + 2] + 2) >> 2;
    v[i] = temp1;
    v[8 + 1 + i] = temp2;
}
}
