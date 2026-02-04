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
    if (siz > 0) {
        for (i = 0; i < siz; i += 2) {
            t[i].val = 0;
            t[i].vis = 0;
            if (i + 1 < siz) {
                t[i + 1].val = 0;
                t[i + 1].vis = 0;
            }
        }
    }
}
