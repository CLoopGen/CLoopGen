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
for (int i = 0; i < 512; i++) {
    nodes[i].child[0] = -1;
    nodes[i].child[1] = -1;
}

}
