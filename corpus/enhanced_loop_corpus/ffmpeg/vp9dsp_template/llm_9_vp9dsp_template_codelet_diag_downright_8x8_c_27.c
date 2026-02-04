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
for (i = 0; i < 4; i += 2) {
    int idx = i;
    v[idx] = (left[idx] + left[idx + 1] + 1) >> 1;
    v[idx + 1] = (left[idx + 1] + left[idx + 2] + 1) >> 1;
    v[9 + idx] = (top[idx] + top[idx + 1] + 1) >> 1;
    v[10 + idx] = (top[idx + 1] + top[idx + 2] + 1) >> 1;
}
}
