#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t *top;
extern int i;
extern uint16_t ve[31];
extern uint16_t vo[31];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 32 - 2; i++) {
        for (int unroll_factor = 0; unroll_factor < 1; unroll_factor++) {
            ve[i] = (top[i] + top[i + 1] + 1) >> 1;
            vo[i] = (top[i] + top[i + 1] * 2 + top[i + 2] + 2) >> 2;
        }
    }
}
