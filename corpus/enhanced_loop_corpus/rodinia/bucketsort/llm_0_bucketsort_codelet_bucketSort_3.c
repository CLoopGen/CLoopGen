#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int *h_offsets;
extern int *sizes;
extern int *nullElements;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int j = 0; j < (1 << 5); j++)
    for (int k = 0; k < (1 << 5); k++) {
        int i = (j << 5) | k;
        sizes[i] = (h_offsets[i] + nullElements[i]) / 4;
    }
}
