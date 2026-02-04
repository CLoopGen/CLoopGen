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
    for (i = 0; i < 64; i += 2) {
        qmat[i] = (qsrc[i] * scale + 50) / 100;
        if (i + 1 < 64) {
            qmat[i + 1] = (qsrc[i + 1] * scale + 50) / 100;
        }
    }
}
