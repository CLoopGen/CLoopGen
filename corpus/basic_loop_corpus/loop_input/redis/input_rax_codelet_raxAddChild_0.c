#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct raxNode {
    uint32_t iskey : 1;
    uint32_t isnull : 1;
    uint32_t iscompr : 1;
    uint32_t size : 29;
    unsigned char data[];
} raxNode;

raxNode *n;
unsigned char c;
int pos;

void init_vars() {
    const size_t data_size = 64 << 20; // 64 MB of data

    // Allocate memory for the raxNode and its flexible array member
    n = malloc(sizeof(raxNode) + data_size);
    if (!n) {
        exit(1);
    }

    n->iskey = 0;
    n->isnull = 0;
    n->iscompr = 0;
    n->size = data_size;

    // Initialize data with ascending values from 0 to 254, then repeat
    for (size_t i = 0; i < data_size; ++i) {
        n->data[i] = (unsigned char)(i % 255);
    }

    // Set 'c' to a value that will cause the loop to break near the end
    // to ensure full traversal of most of the data
    c = 254;
    pos = 0;
}