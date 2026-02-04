#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *reghisto;
extern uint64_t *word;
extern uint8_t *bytes;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < (1 << 14) / 8; j++) {
    if (*word == 0) {
        reghisto[0] += 8;
    } else {
        uint8_t *bytes_local = (uint8_t *)word;
        // Consecutive memory access with unrolled increment pattern
        for (int k = 0; k < 8; k++) {
            reghisto[bytes_local[k]]++;
        }
    }
    word++;
}
}
