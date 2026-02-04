#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int node_idx[1024];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int temp = 257;
for (int i = 0; i < 256; i++) {
    temp = temp + 1; // Create WAW and WAR dependencies on 'temp' across iterations
    node_idx[i] = temp;
}
}
