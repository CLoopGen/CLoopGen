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
for (i = 0; i < 4; i++) {
    int found = 0;
    for (j = 0; j < nlen && !found; j++)
        if (ref_pix[j] == neighbours[i]) {
            found = 1;
        }
    if (!found && nlen < 4)
        ref_pix[nlen++] = neighbours[i];
}
}
