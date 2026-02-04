#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned long i;
extern unsigned long *lres;
extern size_t processed;
extern unsigned long *first_key;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < processed / (sizeof(unsigned long) * 4); ++i) {
        for (size_t j = 0; j < 2; ++j) {
            for (size_t k = 0; k < 2; ++k) {
                size_t idx = j * 2 + k;
                lres[idx] = (first_key[idx] & ~lres[idx]);
            }
        }
        lres += 4;
        first_key += 4;
    }
}
