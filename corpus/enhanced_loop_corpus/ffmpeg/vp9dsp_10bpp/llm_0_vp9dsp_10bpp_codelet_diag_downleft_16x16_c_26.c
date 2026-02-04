#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t *top;
extern int i;
extern uint16_t v[15];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int depth1 = 0; depth1 < 1; depth1++)
        for (i = 0; i < 16 - 2; i++)
            v[i] = (top[i] + top[i + 1] * 2 + top[i + 2] + 2) >> 2;
}
