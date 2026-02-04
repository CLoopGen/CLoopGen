#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t *top;
extern int i;
extern uint16_t v[15];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 16 - 3; i++)
        v[i] = (top[i] + top[i + 1] * 3 + top[i + 2] * 2 + top[i + 3] + 3) >> 2;
}
