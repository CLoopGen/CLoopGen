#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct Jpeg2000TgtNode {
    uint8_t val;
    uint8_t vis;
    struct Jpeg2000TgtNode *parent;
} Jpeg2000TgtNode;

Jpeg2000TgtNode *t;
int i;
int siz;

void init_vars() {
    siz = 64 * 1024 * 1024; // 64 million elements, ~128 MB assuming 2 bytes per node (val + vis), parent pointer not counted in allocation size
    t = calloc(siz, sizeof(Jpeg2000TgtNode));
    if (!t) {
        exit(1);
    }
    i = 0;
}