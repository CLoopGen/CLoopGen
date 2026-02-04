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
    // Variant 1: Consecutive memory access by flattening the 2D iteration into a single loop with stride handling
    int idx = 0;
    for (int k = 0; k < ph * pw; k++) {
        int i = k / pw;
        int j = k % pw;
        t[idx].parent = &t2[((i >> 1) * w) + (j >> 1)];
        idx++;
    }
}
