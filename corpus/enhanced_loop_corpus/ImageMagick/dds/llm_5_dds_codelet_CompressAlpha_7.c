#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  ssize_t *alphas;
extern unsigned char *indices;
extern unsigned char codes[8];
extern size_t error;
extern size_t _usr_index;
extern size_t j;
extern size_t least;
extern size_t value;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols
#define index _usr_index



void loop(){
for (i = 0; i < 16; i++) {
    value = (size_t)alphas[i];
    if (value != (size_t)(-1)) {
        least = (18446744073709551615UL);
        index = 0;
        for (j = 0; j < 8; j++) {
            size_t dist = (value - (size_t)codes[j]);
            dist *= dist;
            least = (dist < least) ? dist : least;
            index = (dist < least) ? j : index;
        }
        indices[i] = (unsigned char)index;
        error += least;
    } else {
        indices[i] = 0;
    }
}
}
