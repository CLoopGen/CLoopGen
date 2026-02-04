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
for (int i = 0; i < 64; i++) {
    for (int j = 0; j < 8; j++) {
        int idx = i * 8 + j;
        nodes[idx].child[0] = -1;
        nodes[idx].child[1] = -1;
    }
}
}
