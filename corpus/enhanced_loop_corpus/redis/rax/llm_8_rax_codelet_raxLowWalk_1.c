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
    size_t step = 1;
    for (j = 0; j + 4 < h->size && i + 4 < len; j += 4, i += 4) {
        if (v[j] != s[i] || v[j+1] != s[i+1] || v[j+2] != s[i+2] || v[j+3] != s[i+3]) {
            j += (v[j] != s[i]) ? 0 : (v[j+1] != s[i+1]) ? 1 : (v[j+2] != s[i+2]) ? 2 : (v[j+3] != s[i+3]) ? 3 : 4;
            i = i - 4 + j - (j - 4);
            break;
        }
    }
    for (; j < h->size && i < len; j++, i++) {
        if (v[j] != s[i])
            break;
    }
}
