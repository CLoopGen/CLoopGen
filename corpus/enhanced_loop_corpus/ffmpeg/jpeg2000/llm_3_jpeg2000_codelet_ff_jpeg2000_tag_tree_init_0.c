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
    // Variant 2: Strided memory access with reversed and non-unit stride to modify access pattern
    // Access every second element in both dimensions, then fill in the gaps in a second pass
    // First pass: process even indices only
    for (i = 0; i < ph; i += 2)
        for (j = 0; j < pw; j += 2)
            t[i * pw + j].parent = &t2[(i >> 1) * w + (j >> 1)];
    
    // Second pass: handle odd indices with offset arithmetic
    for (i = 0; i < ph; i++)
        for (j = (i % 2 == 0) ? 1 : 0; j < pw; j += 2)
            if (!(i % 2 == 0 && j % 2 == 0)) // Skip already processed even-even pairs
                t[i * pw + j].parent = &t2[(i >> 1) * w + (j >> 1)];
}
