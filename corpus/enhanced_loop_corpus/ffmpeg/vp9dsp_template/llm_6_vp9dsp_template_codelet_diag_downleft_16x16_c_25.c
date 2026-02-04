#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *top;
extern int i;
extern uint8_t v[15];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t temp[14];
    for (i = 0; i < 16 - 2; i++)
        temp[i] = (top[i] + top[i + 1] * 2 + top[i + 2] + 2) >> 2;
    for (i = 0; i < 16 - 2; i++)
        v[i] = temp[i];
}
