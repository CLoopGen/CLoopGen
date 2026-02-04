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
v[0] = (left[1] + left[0] + 1) >> 1;
v[1] = (left[2] + left[1] * 2 + left[0] + 2) >> 2;
for (i = 1; i < 32 - 2; i++) {
    v[i * 2] = (left[i + 1] + left[i + 0] + 1) >> 1;
    v[i * 2 + 1] = (left[i + 2] + left[i + 1] * 2 + left[i + 0] + 2) >> 2;
    v[32 * 2 + i] = (top[i - 1] + v[32 * 2 + i - 1] + top[i + 1] + 2) >> 2;
}
v[32 * 2 + 0] = (top[-1] + top[0] * 2 + top[1] + 2) >> 2;
if (32 - 2 > 0) {
    v[32 * 2 + (32 - 2)] = (top[(32 - 3)] + v[32 * 2 + (32 - 3)] + top[(32 - 1)] + 2) >> 2;
}
}
