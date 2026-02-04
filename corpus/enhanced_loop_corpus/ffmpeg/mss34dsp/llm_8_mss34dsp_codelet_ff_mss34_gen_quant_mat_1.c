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
    for (i = 0; i < 32; i++) {
        uint32_t temp1 = (5000U * qsrc[i] + quality / 2) / quality;
        uint32_t temp2 = (5000U * qsrc[i + 32] + quality / 2) / quality;
        qmat[i] = (temp1 + 50) / 100;
        qmat[i + 32] = (temp2 + 50) / 100;
    }
}
