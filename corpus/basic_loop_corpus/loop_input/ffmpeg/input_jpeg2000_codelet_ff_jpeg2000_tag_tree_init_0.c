#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct Jpeg2000TgtNode {
    uint8_t val;
    uint8_t vis;
    struct Jpeg2000TgtNode *parent;
} Jpeg2000TgtNode;

int w;
int pw;
int ph;
Jpeg2000TgtNode *t;
Jpeg2000TgtNode *t2;
int i;
int j;

void init_vars() {
    pw = 1024;
    ph = 1024;
    w = pw * 2;

    t = (Jpeg2000TgtNode*)calloc(pw * ph, sizeof(Jpeg2000TgtNode));
    t2 = (Jpeg2000TgtNode*)calloc(w * ph, sizeof(Jpeg2000TgtNode));
}