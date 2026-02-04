#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int node_idx[1024];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int k = 0; k < 256; k += 4) {
    for (int i = 0; i < 4; i++) {
        int idx = k + i;
        if (idx < 256) {
            node_idx[idx] = 257 + idx;
        }
    }
}
}
