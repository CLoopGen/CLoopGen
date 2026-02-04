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
    int prev = -1;
    for (int i = 0; i < 512; i++) {
        nodes[i].child[0] = prev;
        nodes[i].child[1] = -1;
        prev = i;
    }
}
