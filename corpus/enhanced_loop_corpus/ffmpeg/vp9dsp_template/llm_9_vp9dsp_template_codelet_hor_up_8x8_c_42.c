#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *left;
extern int i;
extern uint8_t v[14];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8 - 3; i += 2) {
    uint8_t temp1 = left[i];
    uint8_t temp2 = left[i + 1];
    uint8_t temp3 = left[i + 2];
    uint8_t temp4 = left[i + 3];
    v[i * 2] = (temp1 + temp2 + 1) >> 1;
    v[i * 2 + 1] = (temp1 + temp2 * 2 + temp3 + 2) >> 2;
    v[(i + 1) * 2] = (temp2 + temp3 + 1) >> 1;
    v[(i + 1) * 2 + 1] = (temp2 + temp3 * 2 + temp4 + 2) >> 2;
}
}
