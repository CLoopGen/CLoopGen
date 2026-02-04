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

extern raxNode *n;
extern unsigned char c;
extern int pos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    volatile int dummy = 0;
    for (pos = 0; pos < n->size; pos++) {
        if (n->data[pos] > c) {
            dummy = pos; // Introduce WAW dependency via dummy
            break;
        }
        dummy = pos + 1; // Loop-carried WAW dependency on dummy
    }
    pos = dummy ? dummy : pos; // Reconcile pos based on dummy to preserve control flow effect
}
