#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int node_idx[1024];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int i = 0; i < 512; i += 2) {
    node_idx[i] = 257 + i;
    node_idx[i+1] = 258 + i;
}
}
