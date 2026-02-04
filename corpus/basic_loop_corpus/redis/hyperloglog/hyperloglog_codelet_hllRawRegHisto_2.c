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
        bytes = (uint8_t *)word;
        reghisto[bytes[0]]++;
        reghisto[bytes[1]]++;
        reghisto[bytes[2]]++;
        reghisto[bytes[3]]++;
        reghisto[bytes[4]]++;
        reghisto[bytes[5]]++;
        reghisto[bytes[6]]++;
        reghisto[bytes[7]]++;
    }
    word++;
}

}
