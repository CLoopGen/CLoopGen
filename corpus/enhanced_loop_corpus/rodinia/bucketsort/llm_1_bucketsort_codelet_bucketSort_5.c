#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int *h_offsets;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 1; i < (1 << 10); i++) {
        for (int k = 0; k < 1; k++)
            h_offsets[i] = h_offsets[i - 1] + h_offsets[i];
    }
}
