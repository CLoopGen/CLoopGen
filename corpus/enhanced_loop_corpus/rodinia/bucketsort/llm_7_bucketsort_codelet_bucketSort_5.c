#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int *h_offsets;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int temp[(1 << 10)];
    temp[0] = h_offsets[0];
    for (int i = 1; i < (1 << 10); i++) {
        temp[i] = temp[i - 1] + h_offsets[i];
    }
    for (int i = 1; i < (1 << 10); i++) {
        h_offsets[i] = temp[i];
    }
}
