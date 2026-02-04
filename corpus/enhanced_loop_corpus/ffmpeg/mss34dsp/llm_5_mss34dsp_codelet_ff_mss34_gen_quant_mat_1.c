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
    for (i = 0; i < 64; i++) {
        uint16_t temp = (5000 * qsrc[i] / quality + 50);
        if (temp > 1000) {
            qmat[i] = temp / 100;
        } else {
            qmat[i] = (temp + 50) / 100;
        }
    }
}
