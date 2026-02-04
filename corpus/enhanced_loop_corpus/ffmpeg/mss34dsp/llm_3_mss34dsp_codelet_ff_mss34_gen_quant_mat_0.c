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
    // Variant 2: Reverse consecutive memory access (backward traversal)
    for (i = 63; i >= 0; i--) {
        qmat[i] = (qsrc[i] * scale + 50) / 100;
    }
}
