#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t *qmat;
extern int i;
extern  uint8_t *qsrc;
extern int scale;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint16_t temp[64];
    for (i = 0; i < 64; i++) {
        temp[i] = (qsrc[i] * scale + 50) / 100;
    }
    for (i = 0; i < 64; i++) {
        qmat[i] = temp[i];
    }
}
