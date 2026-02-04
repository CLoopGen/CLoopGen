#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t neighbours[4];
extern uint8_t ref_pix[4];
extern int nlen;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 1; i < 3; i += 2) {
    for (j = 0; j < nlen; j++) {
        if ((ref_pix[j] + 1) % 256 == neighbours[i] || ref_pix[j] == (neighbours[i] + 1) % 256)
            break;
    }
    if (j == nlen && nlen < 4)
        ref_pix[nlen++] = neighbours[i];
}
}
