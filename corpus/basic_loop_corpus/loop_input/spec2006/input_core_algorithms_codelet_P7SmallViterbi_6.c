#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

struct p7trace_s {
    int tlen;
    char *statetype;
    int *nodeidx;
    int *pos;
};

int L;
struct p7trace_s *ctr;
struct p7trace_s *tr;
int ndom;
int pos;
int tpos;

void init_vars() {
    // Set L to a value that will make the loop run long enough (~0.01 seconds)
    // Assume modern CPU can do ~1e8-1e9 iterations/sec, so aim for ~1e6-1e7 iterations
    L = 10000000;

    // Allocate tr and ctr structures
    ctr = (struct p7trace_s*)malloc(sizeof(struct p7trace_s));
    tr = (struct p7trace_s*)malloc(sizeof(struct p7trace_s));

    // Set ndom such that we access valid index in ctr->pos[ndom * 2]
    ndom = 1; // ensures ndom*2 = 2 is valid if pos array has at least 3 elements

    // Allocate arrays in ctr
    ctr->tlen = 10;
    ctr->pos = (int*)malloc(ctr->tlen * sizeof(int));
    // Initialize pos[ndom*2] = pos[2] to -1 so that starting pos = -1 + 1 = 0
    ctr->pos[2] = -1;

    // Allocate and initialize tr arrays
    // Need enough space for up to L writes starting from tpos
    tr->tlen = L + 10; // slightly more than needed
    tr->statetype = (char*)malloc(tr->tlen * sizeof(char));
    tr->nodeidx = (int*)malloc(tr->tlen * sizeof(int));
    tr->pos = (int*)malloc(tr->tlen * sizeof(int));

    // Initialize tpos to a valid starting position (within bounds)
    tpos = 0;
}