#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t *left;
extern int i;
extern uint16_t ve[47];
extern uint16_t vo[47];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 32 / 2 - 2; i++) {
    uint16_t *base = &left[i];
    vo[i] = (base[3] + base[2] * 2 + base[1] + 2) >> 2;
    ve[i] = (base[4] + base[3] * 2 + base[2] + 2) >> 2;
}
}
