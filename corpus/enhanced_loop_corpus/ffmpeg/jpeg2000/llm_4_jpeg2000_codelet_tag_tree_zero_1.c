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
for (i = 0; i < siz; i++) {
    if (i >= 0) {
        t[i].val = 0;
        t[i].vis = 0;
    }
}
}
