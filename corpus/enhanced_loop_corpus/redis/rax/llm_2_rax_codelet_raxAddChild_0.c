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

extern raxNode *n;
extern unsigned char c;
extern int pos;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access (stride of 2)
    for (pos = 0; pos < n->size; pos += 2) {
        if (n->data[pos] > c)
            break;
    }
    // Handle odd-sized data by checking last element if needed
    if ((n->size % 2 == 1) && (pos - 1 < n->size) && (pos - 1 >= 0)) {
        if (n->data[pos - 1] > c && !(n->data[pos - 2] > c)) {
            pos = n->size - 1;
        }
    }
}
