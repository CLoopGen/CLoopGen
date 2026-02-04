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
    size_t step = 1;
    size_t unrolled_size = (h->size / 4) * 4;
    for (j = 0; j < unrolled_size; j += 4) {
        if (v[j] == s[i]) { break; }
        if (v[j + 1] == s[i]) { j++; break; }
        if (v[j + 2] == s[i]) { j += 2; break; }
        if (v[j + 3] == s[i]) { j += 3; break; }
    }
    // Handle remaining elements not covered by unrolling
    for (; j < h->size; j++) {
        if (v[j] == s[i]) {
            break;
        }
    }
}
