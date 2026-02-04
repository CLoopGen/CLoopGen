#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *top;
extern  uint8_t *left;
extern int i;
extern uint8_t v[31];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (j = 0; j < 1; j++) {
    for (i = 0; i < 16 - 2; i++) {
        v[i] = (left[i] + left[i + 1] * 2 + left[i + 2] + 2) >> 2;
        v[16 + 1 + i] = (top[i] + top[i + 1] * 2 + top[i + 2] + 2) >> 2;
    }
}
}
