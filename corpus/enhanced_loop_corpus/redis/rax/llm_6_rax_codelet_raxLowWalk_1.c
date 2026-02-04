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
    size_t local_j = 0;
    size_t local_i = i;
    unsigned char *local_v = v;
    unsigned char *local_s = s;
    raxNode *local_h = h;
    size_t local_size = local_h->size;
    size_t local_len = len;
    int match = 1;

    for (; local_j < local_size && local_i < local_len; local_j++, local_i++) {
        if (local_v[local_j] != local_s[local_i]) {
            match = 0;
            break;
        }
    }

    j = local_j;
    i = local_i;
}
