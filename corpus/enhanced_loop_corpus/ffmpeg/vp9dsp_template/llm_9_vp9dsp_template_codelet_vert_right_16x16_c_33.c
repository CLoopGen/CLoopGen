#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *top;
extern int i;
extern uint8_t ve[23];
extern uint8_t vo[23];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 2; i < 16 - 2; i++) {
    uint8_t a = top[i];
    uint8_t b = top[i - 2];
    uint8_t c = top[i - 1];
    uint8_t d = top[i + 1];
    uint8_t e = top[i + 2];
    ve[8 + i] = (b + c + a + d + e + 2) / 5;
    vo[8 + i] = (b*2 + c*3 + a*4 + d*3 + e*2 + 8) >> 4;
}
}
