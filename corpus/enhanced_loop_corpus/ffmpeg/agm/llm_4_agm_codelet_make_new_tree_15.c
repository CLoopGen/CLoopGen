#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int node_idx[1024];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < 256; i++) {
        if (i % 2 == 0) {
            node_idx[i] = 257 + i;
        } else {
            node_idx[i] = 257 + i + 1;
        }
    }
}
