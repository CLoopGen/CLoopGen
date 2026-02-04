#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *lens;
extern uint8_t bits[162];
extern uint16_t codes[162];
extern int i;
extern int j;
extern int prefix;
extern int max_bits;
extern int idx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8; i++) {
        int local_shift = 1;
        for (j = 0; j < lens[i] + lens[15 - i]; j++) {
            bits[idx] = i + 1;
            codes[idx] = prefix;
            prefix++;
            idx++;
        }
        max_bits = i + 1;
        prefix <<= local_shift;
    }
}
