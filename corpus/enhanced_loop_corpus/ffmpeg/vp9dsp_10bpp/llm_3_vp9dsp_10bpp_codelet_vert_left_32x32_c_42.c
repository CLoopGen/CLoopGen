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
    uint16_t *t = top;
    uint16_t *ev = ve;
    uint16_t *ov = vo;
    for (i = 0; i < 32 - 2; i++) {
        ev[i] = (t[i] + t[i + 1] + 1) >> 1;
        ov[i] = (t[i] + t[i + 1] * 2 + t[i + 2] + 2) >> 2;
    }
}
