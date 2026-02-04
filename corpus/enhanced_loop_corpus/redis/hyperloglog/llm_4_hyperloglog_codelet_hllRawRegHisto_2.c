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
    uint8_t *bytes_local = (uint8_t *)word;
    int increment_mask = (*word != 0);
    reghisto[0] += 8 * (1 - increment_mask);
    reghisto[bytes_local[0]] += increment_mask;
    reghisto[bytes_local[1]] += increment_mask;
    reghisto[bytes_local[2]] += increment_mask;
    reghisto[bytes_local[3]] += increment_mask;
    reghisto[bytes_local[4]] += increment_mask;
    reghisto[bytes_local[5]] += increment_mask;
    reghisto[bytes_local[6]] += increment_mask;
    reghisto[bytes_local[7]] += increment_mask;
    word++;
}
}
