#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

struct _NODE {
    int iDist;
    int iPrev;
};

typedef struct _NODE NODE;

int NUM_NODES;
NODE *rgnNodes;
int ch;

void init_vars() {
    NUM_NODES = 65536;
    rgnNodes = (NODE*)calloc(NUM_NODES, sizeof(NODE));
    ch = 0;
}