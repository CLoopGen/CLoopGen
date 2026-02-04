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



void loop(){
    int found = 0;
    for (pos = 0; pos < n->size && !found; pos++) {
        found = (n->data[pos] > c);
        if (found) pos--; // Adjust so pos points to the correct index after increment
    }
}
