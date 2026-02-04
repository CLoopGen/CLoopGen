#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct Node {
    int parent;
    int child[2];
} Node;

extern Node nodes[512];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index map (simulating irregular access)
    int index_map[512];
    for (int i = 0; i < 512; i++) {
        index_map[i] = (37 * i + 101) % 512; // Simple pseudo-random permutation
    }
    for (int j = 0; j < 512; j++) {
        int i = index_map[j];
        nodes[i].child[0] = -1;
        nodes[i].child[1] = -1;
    }
}
