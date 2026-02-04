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
    // Variant 2: Reverse consecutive memory access (traverse from end to start)
    for (pos = n->size - 1; pos >= 0; pos--) {
        if (n->data[pos] > c) {
            break;
        }
    }
    // Adjust pos to maintain logical consistency: 
    // If we break, pos is the first (from end) where data[pos] > c.
    // No further adjustment needed as original semantics allow any valid pos.
}
