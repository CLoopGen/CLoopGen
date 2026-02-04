#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int *h_offsets;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int start = (1 << 10) - 1;
    for (int i = start; i > 0; i--) {
        if (i & 1) {
            h_offsets[i] = h_offsets[i - 1];
        } else {
            h_offsets[i] = h_offsets[i] + h_offsets[i - 1];
        }
    }
}
