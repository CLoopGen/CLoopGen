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
    for (i = 0; i < processed; i += sizeof(unsigned long) * 4) {
        size_t unroll_factor = 4;
        for (size_t k = 0; k < unroll_factor; ++k) {
            if (i + k * sizeof(unsigned long) >= processed) break;
            lres[k] = (~first_key[k] & lres[k]);
        }
        lres += 4;
        first_key += 4;
    }
}
