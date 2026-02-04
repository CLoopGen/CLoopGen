#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int node_idx[1024];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int i = 0; i < 128; i++) {
    int base = 257 + 2 * i;
    node_idx[i*2]     = base;
    node_idx[i*2 + 1] = base + 1;
    node_idx[i]       = base + i % 3;
}
}
