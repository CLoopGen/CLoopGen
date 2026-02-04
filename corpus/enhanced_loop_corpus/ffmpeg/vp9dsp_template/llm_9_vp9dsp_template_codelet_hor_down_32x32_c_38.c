#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *top;
extern  uint8_t *left;
extern int i;
extern uint8_t v[94];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i++) {
    int idx = i << 2;
    v[idx] = (left[i + 1] + left[i] + 1) >> 1;
    v[idx + 1] = (left[i + 2] + (left[i + 1] << 1) + left[i] + 2) >> 2;
    v[idx + 2] = (top[i] + top[i + 1] + 1) >> 1;
    v[idx + 3] = (top[i + 1] + (top[i] << 1) + top[i - 1] + 2) >> 2;
}
}
