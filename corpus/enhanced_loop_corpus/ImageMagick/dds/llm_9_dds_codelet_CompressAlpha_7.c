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
for (i = 0; i < 8; i++) {
    if (alphas[2*i] == -1 && alphas[2*i + 1] == -1) {
        indices[2*i] = 0;
        indices[2*i + 1] = 0;
        continue;
    }
    for (j = 0; j < 8; j++) {
        size_t code_val = (size_t)codes[j];
        size_t dist1 = (alphas[2*i] != -1) ? 
            ((size_t)alphas[2*i] - code_val) * ((size_t)alphas[2*i] - code_val) : 
            (18446744073709551615UL);
        size_t dist2 = (alphas[2*i + 1] != -1) ? 
            ((size_t)alphas[2*i + 1] - code_val) * ((size_t)alphas[2*i + 1] - code_val) : 
            (18446744073709551615UL);

        if (alphas[2*i] != -1 && dist1 < least) {
            least = dist1;
            index = j;
        }
        if (alphas[2*i + 1] != -1 && dist2 < least) {
            least = dist2;
            index = j;
        }
    }
    if (alphas[2*i] != -1) {
        indices[2*i] = (unsigned char)index;
        error += least;
    } else {
        indices[2*i] = 0;
    }
    if (alphas[2*i + 1] != -1) {
        indices[2*i + 1] = (unsigned char)index;
        error += least;
    } else {
        indices[2*i + 1] = 0;
    }
    least = (18446744073709551615UL);
}
}
