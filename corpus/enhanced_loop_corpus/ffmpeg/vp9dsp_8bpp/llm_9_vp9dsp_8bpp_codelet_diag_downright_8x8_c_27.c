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
    int idx = i >> 1;
    v[idx] = (left[i] + left[i + 1] + 2) >> 1;
    v[6 + idx] = (top[i] + top[i + 1] + 2) >> 1;
}
}
