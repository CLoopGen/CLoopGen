#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *left;
extern int i;
extern uint8_t v[62];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 30 - 4; i += 2) {
    uint8_t sum1 = left[i] + left[i + 1];
    uint8_t sum2 = left[i + 1] + left[i + 2];
    v[i * 2] = (sum1 + 1) >> 1;
    v[i * 2 + 1] = (sum1 + sum2 + 2) >> 2;
    v[(i + 1) * 2] = (sum2 + left[i + 3] + 1) >> 1;
    v[(i + 1) * 2 + 1] = (sum2 + left[i + 2] * 2 + left[i + 3] + 2) >> 2;
}
}
