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
for (i = 0; i < ph; i++)
    for (j = 0; j < pw; j++)
        t[i * pw + j].parent = &t2[(i >> 1) * w + (j >> 1)];

}
