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
extern size_t len;
extern raxNode *h;
extern size_t i;
extern size_t j;
extern unsigned char *v;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Consecutive memory access with pointer arithmetic (forward traversal)
    unsigned char *vj = v;
    unsigned char *si = s;
    for (j = 0; j < h->size && i < len; j++, i++) {
        if (*vj != *si)
            break;
        vj++;
        si++;
    }
}
