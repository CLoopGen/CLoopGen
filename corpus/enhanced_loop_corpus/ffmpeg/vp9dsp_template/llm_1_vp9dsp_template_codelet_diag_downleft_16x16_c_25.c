#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *top;
extern int i;
extern uint8_t v[15];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 16 - 2; i++) {
        for (int k = 0; k < 1; k++) {
            v[i] = (top[i] + top[i + 1] * 2 + top[i + 2] + 2) >> 2;
        }
    }
}
