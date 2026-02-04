#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int *h_offsets;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int temp = 0;
    for (int i = 0; i < (1 << 10); i++) {
        temp += h_offsets[i];
        h_offsets[i] = temp;
    }
}
