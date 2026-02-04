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
    int j;
    for (i = 0; i < 32; i++) {
        for (j = 0; j < 2; j++) {
            int idx = i * 2 + j;
            uint32_t temp = qsrc[idx] * scale + 100;
            qmat[idx] = (temp + (temp >> 7)) / 200;
        }
    }
}
