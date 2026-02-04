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
    uint64_t temp_word;
    for (j = 0; j < (1 << 14) / 8; j++) {
        temp_word = *word;
        if (temp_word == 0) {
            reghisto[0] += 8;
        } else {
            uint8_t *bytes_local = (uint8_t *)&temp_word;
            reghisto[bytes_local[0]]++;
            reghisto[bytes_local[1]]++;
            reghisto[bytes_local[2]]++;
            reghisto[bytes_local[3]]++;
            reghisto[bytes_local[4]]++;
            reghisto[bytes_local[5]]++;
            reghisto[bytes_local[6]]++;
            reghisto[bytes_local[7]]++;
        }
        word++;
    }
}
