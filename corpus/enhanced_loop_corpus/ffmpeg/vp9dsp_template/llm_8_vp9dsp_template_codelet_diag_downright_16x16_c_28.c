#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *top;
extern  uint8_t *left;
extern int i;
extern uint8_t v[31];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 16 - 4; i += 2) {
    uint8_t temp1 = left[i] + left[i + 1];
    uint8_t temp2 = left[i + 1] + left[i + 2];
    v[i] = (temp1 + temp2 + 2) >> 2;
    uint8_t temp3 = top[i] + top[i + 1];
    uint8_t temp4 = top[i + 1] + top[i + 2];
    v[16 + 1 + i] = (temp3 + temp4 + 2) >> 2;
}
}
