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
    uint8_t temp;
    for (i = 1; i < 4; i++) {
        temp = neighbours[i];
        for (j = 0; j < nlen; j++) {
            if (ref_pix[j] == temp)
                break;
        }
        if (j == nlen)
            ref_pix[nlen++] = temp;
    }
}
