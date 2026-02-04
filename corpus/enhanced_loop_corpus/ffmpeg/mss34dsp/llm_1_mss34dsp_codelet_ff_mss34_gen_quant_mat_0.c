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
    int i0, i1;
    for (i0 = 0; i0 < 4; i0++) {
        for (i1 = 0; i1 < 16; i1++) {
            int idx = i0 * 16 + i1;
            qmat[idx] = (qsrc[idx] * scale + 50) / 100;
        }
    }
}
