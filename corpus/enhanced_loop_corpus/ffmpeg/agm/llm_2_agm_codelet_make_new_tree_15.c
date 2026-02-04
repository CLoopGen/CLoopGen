#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int node_idx[1024];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int i = 0; i < 256; i += 4) {
    node_idx[i] = 257 + i;
    if (i + 1 < 256) node_idx[i + 1] = 257 + i + 1;
    if (i + 2 < 256) node_idx[i + 2] = 257 + i + 2;
    if (i + 3 < 256) node_idx[i + 3] = 257 + i + 3;
}
}
