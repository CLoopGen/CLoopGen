#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned long i;
extern unsigned long *lres;
extern size_t processed;
extern unsigned long *first_key;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    unsigned long temp0, temp1, temp2, temp3;
    for (i = 0; i < processed; i += sizeof(unsigned long) * 4) {
        temp0 = ~lres[0];
        temp1 = ~lres[1];
        temp2 = ~lres[2];
        temp3 = ~lres[3];
        lres[0] = first_key[0] & temp0;
        lres[1] = first_key[1] & temp1;
        lres[2] = first_key[2] & temp2;
        lres[3] = first_key[3] & temp3;
        lres += 4;
        first_key += 4;
    }
}
