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
for (i = 0; i < 16; i += 2) {
    if (alphas[i] == -1) {
        indices[i] = 0;
        indices[i + 1] = 0;
        continue;
    }
    value = (size_t)alphas[i];
    least = (18446744073709551615UL);
    index = 0;
    for (j = 0; j < 8; j++) {
        size_t diff = value - (size_t)codes[j];
        size_t dist = diff * diff;
        if (dist < least) {
            least = dist;
            index = j;
        }
    }
    indices[i] = (unsigned char)index;
    error += least;

    if (i + 1 < 16 && alphas[i + 1] != -1) {
        value = (size_t)alphas[i + 1];
        least = (18446744073709551615UL);
        index = 0;
        for (j = 0; j < 8; j++) {
            size_t diff = value - (size_t)codes[j];
            size_t dist = diff * diff;
            if (dist < least) {
                least = dist;
                index = j;
            }
        }
        indices[i + 1] = (unsigned char)index;
        error += least;
    } else if (i + 1 < 16) {
        indices[i + 1] = 0;
    }
}
}
