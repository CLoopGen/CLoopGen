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
size_t len;
raxNode *h;
size_t i;
size_t j;
unsigned char *v;

void init_vars() {
    // Allocate approximately 64MB of input data to target ~0.01 sec runtime
    len = 64 * 1024 * 1024;
    s = (unsigned char *)malloc(len);
    if (!s) exit(1);
    
    // Fill s with predictable non-repeating pattern
    for (size_t idx = 0; idx < len; idx++) {
        s[idx] = (unsigned char)(idx % 251);
    }
    
    // h->size will control v length; make it large enough to avoid trivial break
    size_t h_size = 8 * 1024 * 1024;
    // Allocate raxNode with embedded data of size h_size
    h = (raxNode *)malloc(sizeof(raxNode) + h_size * sizeof(unsigned char));
    if (!h) exit(1);
    
    h->iskey = 0;
    h->isnull = 0;
    h->iscompr = 0;
    h->size = h_size;
    
    v = (unsigned char *)malloc(h_size * sizeof(unsigned char));
    if (!v) exit(1);
    
    // Initialize v to match prefix of s as much as possible to ensure loop runs deep
    size_t min_len = h_size < len ? h_size : len;
    memcpy(v, s, min_len);
    
    // Ensure that the loop won't run indefinitely and has a realistic chance to break
    // Modify last few elements to eventually trigger the break condition
    if (min_len > 0) {
        v[min_len - 1] ^= 1;  // Make last byte differ to ensure break happens
    }
    
    // Initialize loop counters
    i = 0;
    j = 0;
}