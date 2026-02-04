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
        size_t idx = i / sizeof(unsigned long);
        lres[idx + 0] = (first_key[idx + 0] & lres[idx + 0]);
        lres[idx + 1] = (first_key[idx + 1] & lres[idx + 1]);
        lres[idx + 2] = (first_key[idx + 2] & lres[idx + 2]);
        lres[idx + 3] = (first_key[idx + 3] & lres[idx + 3]);
    }
}
