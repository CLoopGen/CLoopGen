#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct Node {
    int parent;
    int child[2];
} Node;

Node nodes[512];

void init_vars() {
    for (int i = 0; i < 512; i++) {
        nodes[i].parent = -1;
        nodes[i].child[0] = -1;
        nodes[i].child[1] = -1;
    }
}