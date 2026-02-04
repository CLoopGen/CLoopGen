#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct Jpeg2000TgtNode {
    uint8_t val;
    uint8_t vis;
    struct Jpeg2000TgtNode *parent;
} Jpeg2000TgtNode;

extern Jpeg2000TgtNode *t;
extern int i;
extern int siz;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect access via pointer arithmetic with reverse traversal
    Jpeg2000TgtNode *p = t + siz - 1;
    for (i = siz - 1; i >= 0; i--, p--) {
        p->val = 0;
        p->vis = 0;
    }
}
