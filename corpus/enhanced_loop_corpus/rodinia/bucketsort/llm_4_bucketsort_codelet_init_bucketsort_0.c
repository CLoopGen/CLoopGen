#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int *h_offsets;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < (1 << 10); i++) {
        if (!(i & 1)) {
            h_offsets[i] = 0;
        } else {
            h_offsets[i] = 0;
        }
    }
}
