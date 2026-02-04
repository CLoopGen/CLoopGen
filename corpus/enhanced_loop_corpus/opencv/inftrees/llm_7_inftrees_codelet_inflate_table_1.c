#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned short *lens;
extern unsigned int codes;
extern unsigned int sym;
extern unsigned short count[16];

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    unsigned int local_sym = 0;
    while (local_sym < codes) {
        unsigned short l = lens[local_sym];
        count[l] = count[l] + 1;
        local_sym++;
    }
}
