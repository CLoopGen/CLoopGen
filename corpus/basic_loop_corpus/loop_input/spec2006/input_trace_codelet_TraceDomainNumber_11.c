#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

struct p7trace_s {
    int tlen;
    char *statetype;
    int *nodeidx;
    int *pos;
};

struct p7trace_s *tr;
int i;
int ndom;

void init_vars() {
    tr = (struct p7trace_s *)malloc(sizeof(struct p7trace_s));
    tr->tlen = 134217728; // ~128MB of data to target ~0.01 sec runtime
    tr->statetype = (char *)malloc(tr->tlen * sizeof(char));
    tr->nodeidx = (int *)malloc(tr->tlen * sizeof(int));
    tr->pos = (int *)malloc(tr->tlen * sizeof(int));

    for (int idx = 0; idx < tr->tlen; idx++) {
        tr->statetype[idx] = (idx % 7); // values 0..6 cyclically, so some match condition == 6
        tr->nodeidx[idx] = idx;
        tr->pos[idx] = idx * 2;
    }

    i = 0;
    ndom = 0;
}