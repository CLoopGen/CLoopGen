#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *top;
extern int i;
extern uint8_t v[31];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < 30; i++) {
        uint8_t a = top[i - 1];
        uint8_t b = top[i];
        uint8_t c = top[i + 1];
        uint8_t temp1 = (a + b) >> 1;
        uint8_t temp2 = (b + c) >> 1;
        v[i] = (temp1 + temp2 + 1) >> 1;
    }
}
