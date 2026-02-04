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
    size_t temp_error = 0;
    for (i = 0; i < 16; i++) {
        if (alphas[i] == -1) {
            indices[i] = 0;
            continue;
        }
        value = (size_t)alphas[i];
        least = (18446744073709551615UL);
        index = 0;
        for (j = 0; j < 8; j++) {
            size_t dist;
            dist = value - (size_t)codes[j];
            dist *= dist;
            if (dist < least) {
                least = dist;
                index = j;
            }
        }
        indices[i] = (unsigned char)index;
        temp_error += least;
    }
    error += temp_error;
}
