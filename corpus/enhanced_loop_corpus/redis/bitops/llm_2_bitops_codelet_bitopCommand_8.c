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
    // Variant 1: Consecutive (unit-stride) memory access with unrolling but sequential array traversal
    for (i = 0; i < processed / sizeof(unsigned long); i += 4) {
        size_t idx = i;
        lres[idx + 0] = (first_key[idx + 0] & ~lres[idx + 0]);
        lres[idx + 1] = (first_key[idx + 1] & ~lres[idx + 1]);
        lres[idx + 2] = (first_key[idx + 2] & ~lres[idx + 2]);
        lres[idx + 3] = (first_key[idx + 3] & ~lres[idx + 3]);
    }
}
