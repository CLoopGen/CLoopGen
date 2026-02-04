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
    qmat[0] = (qsrc[0] * scale + 50) / 100;
    for (i = 1; i < 64; i++) {
        qmat[i] = (qsrc[i] * scale + qsrc[i-1]) / 100;
    }
}
