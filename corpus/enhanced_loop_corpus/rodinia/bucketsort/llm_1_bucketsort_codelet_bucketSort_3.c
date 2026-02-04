#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int *h_offsets;
extern int *sizes;
extern int *nullElements;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int i = 0; i < (1 << 10); i += 4) {
    sizes[i]     = (h_offsets[i]     + nullElements[i])     / 4;
    sizes[i + 1] = (h_offsets[i + 1] + nullElements[i + 1]) / 4;
    sizes[i + 2] = (h_offsets[i + 2] + nullElements[i + 2]) / 4;
    sizes[i + 3] = (h_offsets[i + 3] + nullElements[i + 3]) / 4;
}
}
