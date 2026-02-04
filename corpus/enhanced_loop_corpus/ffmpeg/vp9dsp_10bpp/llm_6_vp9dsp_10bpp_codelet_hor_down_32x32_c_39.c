#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t *top;
extern  uint16_t *left;
extern int i;
extern uint16_t v[94];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 32 - 2; i++) {
    uint16_t temp1 = (left[i + 1] + left[i + 0] + 1) >> 1;
    uint16_t temp2 = (left[i + 2] + left[i + 1] * 2 + left[i + 0] + 2) >> 2;
    v[i * 2] = temp1;
    v[i * 2 + 1] = temp2;
    if (i > 0) {
        v[32 * 2 + i] = (top[i - 1] + top[i] * 2 + top[i + 1] + 2) >> 2;
    }
}
v[32 * 2 + 0] = (top[0] * 2 + top[1] + 2) >> 2;
}
