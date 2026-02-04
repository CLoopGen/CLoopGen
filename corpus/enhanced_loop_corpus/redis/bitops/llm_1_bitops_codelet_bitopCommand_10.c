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
    for (i = 0; i < processed; i += sizeof(unsigned long)) {
        lres[0] = (first_key[0] & lres[0]);
        lres += 1;
        first_key += 1;
    }
}
