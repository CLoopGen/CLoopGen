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
    // Reduced trip count with unrolled lightweight operations
    for (j = 0; j < (1 << 10); j += 2) {
        uint64_t val1 = word[0];
        uint64_t val2 = word[1];

        // Process first word
        if (val1 == 0) {
            reghisto[0] += 8;
        } else {
            uint8_t *b1 = (uint8_t *)&val1;
            reghisto[b1[0]]++; reghisto[b1[1]]++;
            reghisto[b1[2]]++; reghisto[b1[3]]++;
        }

        // Process second word
        if (val2 == 0) {
            reghisto[0] += 8;
        } else {
            uint8_t *b2 = (uint8_t *)&val2;
            reghisto[b2[4]]++; reghisto[b2[5]]++;
            reghisto[b2[6]]++; reghisto[b2[7]]++;
        }

        word += 2; // Advance pointer by two elements
    }
}
