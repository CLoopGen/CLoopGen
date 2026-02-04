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
for (i = 0; i < 16; i++) {
    v[i * 2] = (left[i + 1] + left[i] + 1) >> 1;
    v[i * 2 + 1] = (left[i + 2] + left[i + 1] + left[i] + 1) >> 1;
    v[32 * 2 + i * 2] = (top[i] + top[i + 1] + 1) >> 1;
    v[32 * 2 + i * 2 + 1] = (top[i + 1] + top[i + 2] + 1) >> 1;
}
}
