#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t *left;
extern int i;
extern uint16_t v[62];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint16_t temp;
    for (i = 0; i < 32 - 2; i++) {
        temp = (left[i] + left[i + 1] + 1) >> 1;
        v[i * 2] = temp;
        v[i * 2 + 1] = (temp + left[i + 1] + left[i + 2] + 2) >> 2;
    }
}
