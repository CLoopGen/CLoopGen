#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  ssize_t *map;
extern  unsigned char *source;
extern unsigned char *target;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned char local_target[16];
    for (i = 0; i < 16; i++) {
        if (map[i] == -1)
            local_target[i] = 3;
        else
            local_target[i] = source[map[i]];
    }
    // Eliminate loop-carried dependence by separating store from compute
    for (i = 0; i < 16; i++) {
        target[i] = local_target[i];  // WAW hazard removed, no overlapping write-read in same location
    }
}
