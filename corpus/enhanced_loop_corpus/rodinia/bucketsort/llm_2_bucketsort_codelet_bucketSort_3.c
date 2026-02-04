#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int *h_offsets;
extern int *sizes;
extern int *nullElements;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access (stride of 2)
    for (int i = 0; i < (1 << 10); i += 2) {
        sizes[i] = (h_offsets[i] + nullElements[i]) / 4;
        if (i + 1 < (1 << 10)) {
            sizes[i + 1] = (h_offsets[i + 1] + nullElements[i + 1]) / 4;
        }
    }
}
