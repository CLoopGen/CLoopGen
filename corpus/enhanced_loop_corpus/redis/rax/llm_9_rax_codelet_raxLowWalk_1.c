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



void loop(){
    size_t limit = (h->size < len) ? h->size : len;
    size_t unroll_factor = 2;
    size_t remainder = limit % unroll_factor;
    size_t unrolled_limit = limit - remainder;

    for (j = 0; j < unrolled_limit; j += unroll_factor, i += unroll_factor) {
        if (v[j] != s[i]) break;
        if (v[j+1] != s[i+1]) {
            j++;
            i++;
            break;
        }
    }

    for (; j < h->size && i < len; j++, i++) {
        if (v[j] != s[i])
            break;
    }
}
