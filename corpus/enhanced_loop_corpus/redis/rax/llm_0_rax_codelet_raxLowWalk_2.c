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
    for (size_t level1 = 0; level1 < h->size; level1++) {
        for (j = 0; j <= level1; j++) {
            if (v[j] == s[i])
                goto exit_loop;
        }
    }
    // If no match was found, j ends up equal to h->size
    j = h->size;
    return;
exit_loop:
    return;
}
