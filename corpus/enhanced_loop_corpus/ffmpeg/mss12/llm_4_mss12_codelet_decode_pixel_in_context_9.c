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
    for (i = 1; i < 4; i++) {
        j = 0;
        for (; j < nlen && ref_pix[j] != neighbours[i]; j++);
        if (j == nlen)
            ref_pix[nlen++] = neighbours[i];
    }
}
