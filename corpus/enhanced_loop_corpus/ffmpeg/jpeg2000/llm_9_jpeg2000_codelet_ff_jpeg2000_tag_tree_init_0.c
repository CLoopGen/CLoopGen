#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct Jpeg2000TgtNode {
    uint8_t val;
    uint8_t vis;
    struct Jpeg2000TgtNode *parent;
} Jpeg2000TgtNode;

extern int w;
extern int pw;
extern int ph;
extern Jpeg2000TgtNode *t;
extern Jpeg2000TgtNode *t2;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i, j;
    int total_elements = ph * pw;
    int idx;
    for (idx = 0; idx < total_elements; idx++) {
        i = idx / pw;
        j = idx % pw;
        if ((i & 1) == 0 && (j & 1) == 0) {
            t[idx].parent = &t2[(i >> 1) * w + (j >> 1)];
        } else if ((i & 1) == 0) {
            t[idx].parent = t[idx - 1].parent;
        } else if ((j & 1) == 0) {
            t[idx].parent = t[idx - pw].parent;
        } else {
            t[idx].parent = t[idx - pw - 1].parent;
        }
    }
}
