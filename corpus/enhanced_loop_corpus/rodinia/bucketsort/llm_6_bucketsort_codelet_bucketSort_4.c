#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int *h_offsets;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int temp[1 << 10];
    for (int i = 0; i < (1 << 10); i++) {
        temp[i] = h_offsets[i];
    }
    for (int i = 0; i < (1 << 10); i++) {
        if ((temp[i] % 4) != 0)
            h_offsets[i] = (temp[i] & ~3) + 4;
    }
}
