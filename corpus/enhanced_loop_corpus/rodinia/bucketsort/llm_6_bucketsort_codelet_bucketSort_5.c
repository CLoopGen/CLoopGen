#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int *h_offsets;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 1; i < (1 << 10); i += 2) {
        if (i + 1 < (1 << 10)) {
            h_offsets[i] = h_offsets[i - 1] + h_offsets[i];
            h_offsets[i + 1] = h_offsets[i] + h_offsets[i + 1];
        } else {
            h_offsets[i] = h_offsets[i - 1] + h_offsets[i];
        }
    }
}
