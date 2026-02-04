#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *left;
extern int i;
extern uint8_t ve[11];
extern uint8_t vo[11];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8 / 2 - 3; i++) {
    uint8_t a = left[i * 2 + 3];
    uint8_t b = left[i * 2 + 2];
    uint8_t c = left[i * 2 + 1];
    uint8_t d = left[i * 2 + 4];
    vo[i] = (a + b + b + c + 3) >> 2;
    ve[i] = (d + a + a + b + 3) >> 2;
}
}
