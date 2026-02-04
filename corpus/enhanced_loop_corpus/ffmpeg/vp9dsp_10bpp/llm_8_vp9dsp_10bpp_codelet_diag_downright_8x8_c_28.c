#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t *top;
extern  uint16_t *left;
extern int i;
extern uint16_t v[15];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8 - 1; i++) {
    v[i] = (left[i] + left[i + 1] * 3 + left[i + 2] + left[i + 3] + 2) >> 2;
    v[8 + 1 + i] = (top[i] + top[i + 1] * 3 + top[i + 2] + top[i + 3] + 2) >> 2;
}
}
