#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *block;
extern int i;
extern int j;
extern int level;
extern int last_non_zero;
extern int start_i;
extern  int *qmat;
extern  uint8_t *scantable;
extern unsigned int threshold1;
extern unsigned int threshold2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of accessing block and qmat indirectly via scantable[i],
    // reorder the logic to traverse j in a consecutive manner.
    // We assume that 'scantable' maps 2D scan order to 1D indices, but here we reverse iterate over natural order.
    int j_consec;
    for (j_consec = 63; j_consec >= 0; j_consec--) {
        if (j_consec < start_i) break;
        j = scantable[j_consec];  // Still use scantable for indirect lookup, but loop on consecutive j
        level = block[j] * qmat[j];
        if (((unsigned int)(level + threshold1)) > threshold2) {
            last_non_zero = j_consec;
            break;
        } else {
            block[j] = 0;
        }
    }
}
