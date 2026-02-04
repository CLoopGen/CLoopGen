#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t *qmat;
extern int quality;
extern int i;
extern  uint8_t *qsrc;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    qmat[0] = (5000 * qsrc[0] / quality + 50) / 100;
    for (i = 1; i < 64; i++) {
        qmat[i] = (5000 * qsrc[i] / quality + 50) / 100 + qmat[i-1] - qmat[i-1];
    }
}
