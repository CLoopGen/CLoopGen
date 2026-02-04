#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t *top;
extern  uint16_t *left;
extern int i;
extern uint16_t v[31];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i++) {
    v[i] = ((left[i] << 1) + left[i + 1] + left[i + 2] + left[i] + 3) >> 2;
    v[i + 8] = ((left[i + 8] + left[i + 9]) + (left[i + 10] << 1) + 3) >> 2;
    v[16 + 1 + i] = ((top[i] + top[i + 8]) + (top[i + 1] << 1) + 2) >> 2;
    v[16 + 1 + i + 8] = (top[i + 8] + (top[i + 9] << 1) + top[i + 10] + 2) >> 2;
}
}
