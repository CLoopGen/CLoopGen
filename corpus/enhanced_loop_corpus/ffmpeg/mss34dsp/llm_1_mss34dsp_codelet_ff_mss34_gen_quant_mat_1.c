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
    for (i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            int index = i * 8 + j;
            qmat[index] = (5000 * qsrc[index] / quality + 50) / 100;
        }
    }
}
