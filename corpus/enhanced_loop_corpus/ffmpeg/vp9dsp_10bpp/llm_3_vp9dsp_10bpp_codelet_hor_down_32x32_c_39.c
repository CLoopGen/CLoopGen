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
for (i = 0; i < 32 - 2; i += 2) {
    int j = i;
    int k = 32 - 2 - i;
    v[j * 2] = (left[j + 1] + left[j + 0] + 1) >> 1;
    v[j * 2 + 1] = (left[j + 2] + left[j + 1] * 2 + left[j + 0] + 2) >> 2;
    v[64 + j] = (top[j - 1] + top[j] * 2 + top[j + 1] + 2) >> 2;

    if (i + 1 < 32 - 2) {
        v[k * 2] = (left[k + 1] + left[k + 0] + 1) >> 1;
        v[k * 2 + 1] = (left[k + 2] + left[k + 1] * 2 + left[k + 0] + 2) >> 2;
        v[64 + k] = (top[k - 1] + top[k] * 2 + top[k + 1] + 2) >> 2;
    }
}
}
