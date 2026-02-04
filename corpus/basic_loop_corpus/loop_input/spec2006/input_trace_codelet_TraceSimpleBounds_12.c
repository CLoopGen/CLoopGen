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
int i1;
int k1;
int tpos;

void init_vars() {
    const int data_size = 64 * 1024 * 1024; // ~64M elements for ~0.01 sec runtime estimate

    tr = (struct p7trace_s *)malloc(sizeof(struct p7trace_s));
    tr->tlen = data_size;
    tr->statetype = (char *)malloc(data_size * sizeof(char));
    tr->nodeidx = (int *)malloc(data_size * sizeof(int));
    tr->pos = (int *)malloc(data_size * sizeof(int));

    for (int i = 0; i < data_size; i++) {
        tr->statetype[i] = (i == data_size - 1) ? 1 : (i % 3 == 0) ? 2 : 0;
        tr->nodeidx[i] = i;
        tr->pos[i] = i * 2;
    }

    i1 = -1;
    k1 = -1;
    tpos = 0;
}