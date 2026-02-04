#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *top;
extern  uint8_t *left;
extern int i;
extern uint8_t v[15];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8 - 2; i++) {
    int idx = i;
    v[idx] = (left[idx] + left[idx + 1] * 2 + left[idx + 2] + 2) >> 2;
    v[8 + 1 + idx] = (top[idx] + top[idx + 1] * 2 + top[idx + 2] + 2) >> 2;
}
}
