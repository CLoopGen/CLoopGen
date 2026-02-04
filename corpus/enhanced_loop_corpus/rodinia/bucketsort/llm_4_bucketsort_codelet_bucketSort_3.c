#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int *h_offsets;
extern int *sizes;
extern int *nullElements;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < (1 << 10); i++) {
        if ((h_offsets[i] + nullElements[i]) >= 0) {
            sizes[i] = (h_offsets[i] + nullElements[i]) / 4;
        } else {
            sizes[i] = 0;
        }
    }
}
