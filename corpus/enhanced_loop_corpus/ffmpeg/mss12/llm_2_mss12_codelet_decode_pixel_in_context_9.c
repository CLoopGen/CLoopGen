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
    // Variant 1: Strided memory access with stride of 2 (wrapping around using modulo)
    // This changes the access pattern on ref_pix to be non-consecutive
    for (i = 1; i < 4; i++) {
        int found = 0;
        for (j = 0; j < nlen; j++) {
            int idx = (2 * j) % nlen; // Strided access: every second element, wrap if needed
            if (ref_pix[idx] == neighbours[i]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            ref_pix[nlen++] = neighbours[i];
        }
    }
}
