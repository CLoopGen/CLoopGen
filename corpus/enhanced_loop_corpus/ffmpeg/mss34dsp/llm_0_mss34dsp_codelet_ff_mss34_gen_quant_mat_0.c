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
    int outer, inner;
    for (outer = 0; outer < 8; outer++) {
        for (inner = 0; inner < 8; inner++) {
            int idx = outer * 8 + inner;
            qmat[idx] = (qsrc[idx] * scale + 50) / 100;
        }
    }
}
