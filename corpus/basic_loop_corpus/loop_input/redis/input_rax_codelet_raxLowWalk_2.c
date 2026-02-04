#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

typedef struct raxNode {
    uint32_t iskey : 1;
    uint32_t isnull : 1;
    uint32_t iscompr : 1;
    uint32_t size : 29;
    unsigned char data[];
} raxNode;

unsigned char *s;
raxNode *h;
size_t i;
size_t j;
unsigned char *v;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // 64 MB to target ~0.01 sec runtime

    // Allocate s as a large byte array
    s = (unsigned char *)malloc(data_size);
    if (!s) exit(1);
    
    // Initialize s with non-uniform data
    for (size_t idx = 0; idx < data_size; idx++) {
        s[idx] = (unsigned char)(idx % 251);
    }

    // Allocate h with space for its data array
    h = (raxNode *)malloc(sizeof(raxNode) + data_size);
    if (!h) exit(1);
    h->iskey = 0;
    h->isnull = 0;
    h->iscompr = 0;
    h->size = data_size; // Set size to control loop iterations

    v = h->data;
    // Initialize v with data that will not cause immediate break, so loop runs full course
    for (size_t idx = 0; idx < data_size; idx++) {
        v[idx] = (unsigned char)((idx + 41) % 251); // different pattern from s
    }

    i = data_size / 2; // valid index within s bounds
}