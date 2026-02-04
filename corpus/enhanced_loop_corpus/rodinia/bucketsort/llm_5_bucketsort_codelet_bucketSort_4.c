#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int *h_offsets;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < (1 << 10); i++) {
        unsigned int val = h_offsets[i];
        h_offsets[i] = (val % 4 == 0) ? val : ((val & ~3) + 4);
    }
}
