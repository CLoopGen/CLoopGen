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
    for (int i = 0; i < 512; i += 4) {
        nodes[i].child[0] = -1; nodes[i].child[1] = -1;
        if (i + 1 < 512) { nodes[i + 1].child[0] = -1; nodes[i + 1].child[1] = -1; }
        if (i + 2 < 512) { nodes[i + 2].child[0] = -1; nodes[i + 2].child[1] = -1; }
        if (i + 3 < 512) { nodes[i + 3].child[0] = -1; nodes[i + 3].child[1] = -1; }
    }
}
