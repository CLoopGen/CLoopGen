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
    for (i = 0; i < 64; i++) {
        int val = qsrc[i] * scale;
        if (val > 0) {
            qmat[i] = (val + 50) / 100;
        } else {
            qmat[i] = 0;
        }
    }
}
