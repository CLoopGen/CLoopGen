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
    // Variant 2: Indirect memory access via an index mapping array
    // Introduces an auxiliary lookup to simulate irregular access patterns
    int map[4];
    for (int k = 0; k < nlen && k < 4; k++) {
        map[k] = (k * k) % 4; // Simple non-linear index mapping: indirect addressing
    }
    for (i = 1; i < 4; i++) {
        int found = 0;
        for (j = 0; j < nlen; j++) {
            int mapped_index = map[j % 4]; // Use mapped index for indirect access
            if (ref_pix[mapped_index] == neighbours[i]) {
                found = 1;
                break;
            }
        }
        if (!found && nlen < 4) { // Prevent overflow since we use mod 4
            ref_pix[nlen++] = neighbours[i];
        }
    }
}
