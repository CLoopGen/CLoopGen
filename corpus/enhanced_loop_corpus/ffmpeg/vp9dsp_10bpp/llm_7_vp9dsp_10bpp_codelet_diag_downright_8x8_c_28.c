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
    uint16_t acc = 0;
    for (i = 0; i < 8 - 2; i++) {
        acc += left[i]; 
        v[i] = (acc + left[i + 1] * 2 + left[i + 2] + 2) >> 2;
        v[8 + 1 + i] = (top[i] + top[i + 1] * 2 + top[i + 2] + 2 + (i > 0 ? v[i-1] : 0)) >> 2;
    }
}
