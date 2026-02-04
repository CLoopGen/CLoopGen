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
    unsigned int temp_count[16] = {0};
    for (unsigned int i = 0; i < codes; i++) {
        unsigned short len = lens[i];
        temp_count[len] += 1;
    }
    for (int j = 0; j < 16; j++) {
        count[j] += temp_count[j];
    }
}
