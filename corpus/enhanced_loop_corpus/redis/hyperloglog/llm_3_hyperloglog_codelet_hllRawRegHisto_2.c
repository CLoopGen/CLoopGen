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
// Strided access: process every other 8-byte block, then revisit the skipped ones
for (j = 0; j < (1 << 14) / 8; j += 2) {
    uint64_t *first_word = word + j;
    uint64_t *second_word = word + j + 1;

    // Process current strided element
    if (*first_word == 0) {
        reghisto[0] += 8;
    } else {
        uint8_t *bytes1 = (uint8_t *)first_word;
        reghisto[bytes1[0]]++;
        reghisto[bytes1[1]]++;
        reghisto[bytes1[2]]++;
        reghisto[bytes1[3]]++;
        reghisto[bytes1[4]]++;
        reghisto[bytes1[5]]++;
        reghisto[bytes1[6]]++;
        reghisto[bytes1[7]]++;
    }

    // Process next (strided) if within bounds
    if (j + 1 < (1 << 14) / 8) {
        if (*second_word == 0) {
            reghisto[0] += 8;
        } else {
            uint8_t *bytes2 = (uint8_t *)second_word;
            reghisto[bytes2[0]]++;
            reghisto[bytes2[1]]++;
            reghisto[bytes2[2]]++;
            reghisto[bytes2[3]]++;
            reghisto[bytes2[4]]++;
            reghisto[bytes2[5]]++;
            reghisto[bytes2[6]]++;
            reghisto[bytes2[7]]++;
        }
    }
}
}
