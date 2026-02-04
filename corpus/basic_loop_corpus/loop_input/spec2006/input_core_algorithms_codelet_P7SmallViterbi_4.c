#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

struct p7trace_s {
    int tlen;
    char *statetype;
    int *nodeidx;
    int *pos;
};

struct p7trace_s *ctr;
struct p7trace_s *tr;
int pos;
int tpos;

void init_vars() {
    // Allocate and initialize ctr
    ctr = (struct p7trace_s *)malloc(sizeof(struct p7trace_s));
    ctr->tlen = 100000;  // Arbitrary length, not used directly in loop
    ctr->pos = (int *)malloc(sizeof(int));
    ctr->pos[1] = 50000;  // Set loop bound to ensure memory safety and ~0.01s runtime

    // Allocate and initialize tr
    tr = (struct p7trace_s *)malloc(sizeof(struct p7trace_s));
    tr->tlen = ctr->pos[1];
    tr->statetype = (char *)malloc(tr->tlen * sizeof(char));
    tr->nodeidx = (int *)malloc(tr->tlen * sizeof(int));
    tr->pos = (int *)malloc(tr->tlen * sizeof(int));

    // Initialize tpos
    tpos = 0;
}