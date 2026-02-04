#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

struct p7trace_s {
    int tlen;
    char *statetype;
    int *nodeidx;
    int *pos;
};

struct p7trace_s *tr;
char *statetype;
int *nodeidx;
int *pos;
int opos;
int npos;

void init_vars() {
    // Set data size to achieve ~0.01 sec runtime: use ~16M elements as typical modern CPU
    // can process millions of iterations per second in simple loops.
    int size = 16 * 1024 * 1024; // 16 million elements

    // Allocate tr structure
    tr = (struct p7trace_s*)malloc(sizeof(struct p7trace_s));
    
    // Allocate and initialize tr's arrays
    tr->tlen = size;
    tr->statetype = (char*)malloc(size * sizeof(char));
    tr->nodeidx = (int*)malloc(size * sizeof(int));
    tr->pos = (int*)malloc(size * sizeof(int));

    // Initialize tr's data with dummy values
    for (int i = 0; i < size; i++) {
        tr->statetype[i] = (char)('A' + (i % 26));
        tr->nodeidx[i] = i % 1000;
        tr->pos[i] = size - i;
    }

    // Allocate output arrays
    statetype = (char*)malloc(size * sizeof(char));
    nodeidx = (int*)malloc(size * sizeof(int));
    pos = (int*)malloc(size * sizeof(int));
}