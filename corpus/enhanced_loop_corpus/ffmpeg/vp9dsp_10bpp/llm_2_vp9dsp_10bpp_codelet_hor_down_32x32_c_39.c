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
    int idx = i;
    v[idx * 2] = (left[idx + 1] + left[idx + 0] + 1) >> 1;
    v[idx * 2 + 1] = (left[idx + 2] + left[idx + 1] * 2 + left[idx + 0] + 2) >> 2;
    v[64 + idx] = (top[idx - 1] + top[idx] * 2 + top[idx + 1] + 2) >> 2;
}
}
