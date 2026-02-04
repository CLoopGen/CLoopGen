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

extern unsigned char *s;
extern raxNode *h;
extern size_t i;
extern size_t j;
extern unsigned char *v;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t found = 0;
    for (j = 0; j < h->size && !found; j++) {
        unsigned char c = v[j]; // Local copy of v[j]
        if (c == s[i]) {
            found = 1; // Introduce loop-carried dependency via 'found' (scalar evolution)
            j++; // Artificially modify j to skip next element (WAR: write after read)
        }
        v[j] = v[j]; // Redundant self-assignment to introduce WAW on v (no semantic change)
    }
    if (found) j--; // Adjust j to point to matched index
}
