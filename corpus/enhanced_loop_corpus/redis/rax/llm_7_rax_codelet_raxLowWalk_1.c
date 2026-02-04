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
    size_t temp_j = j;
    size_t temp_i = i;
    int mismatch_found = 0;

    for (; temp_j < h->size && temp_i < len && !mismatch_found; ) {
        mismatch_found = (v[temp_j] != s[temp_i]);
        temp_j++;
        temp_i++;
    }

    if (mismatch_found) {
        temp_j--;
        temp_i--;
    }

    j = temp_j;
    i = temp_i;
}
