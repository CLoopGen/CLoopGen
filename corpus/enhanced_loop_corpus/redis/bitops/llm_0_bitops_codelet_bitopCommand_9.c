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
        for (size_t j = 0; j < 4; ++j) {
            lres[j] = (~first_key[j] & lres[j]);
        }
        lres += 4;
        first_key += 4;
    }
}
