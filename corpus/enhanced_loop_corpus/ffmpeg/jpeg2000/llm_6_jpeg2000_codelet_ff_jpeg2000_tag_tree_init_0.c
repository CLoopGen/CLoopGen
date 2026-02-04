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
    Jpeg2000TgtNode *base_t = t;
    Jpeg2000TgtNode *base_t2 = t2;
    int idx, idx2;
    for (i = 0; i < ph; i++) {
        for (j = 0; j < pw; j++) {
            idx = i * pw + j;
            idx2 = (i >> 1) * w + (j >> 1);
            base_t[idx].parent = &base_t2[idx2];
        }
    }
}
