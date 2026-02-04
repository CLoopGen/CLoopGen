#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int *h_offsets;
extern int *sizes;
extern int *nullElements;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < (1 << 9); i += 2) {
        sizes[i] = (h_offsets[i] + nullElements[i] + h_offsets[i+1] + nullElements[i+1]) / 8;
    }
}
