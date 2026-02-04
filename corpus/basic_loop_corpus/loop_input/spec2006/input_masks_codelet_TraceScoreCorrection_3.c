#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

struct p7trace_s {
    int tlen;
    char *statetype;
    int *nodeidx;
    int *pos;
};

struct p7trace_s *tr;
char *dsq;
int sc[24];
int tpos;
int score;

void init_vars() {
    const int data_size = 16777216; // ~16MB to target ~0.01 sec runtime
    tr = (struct p7trace_s *)malloc(sizeof(struct p7trace_s));
    tr->tlen = data_size;
    tr->statetype = (char *)malloc(data_size * sizeof(char));
    tr->nodeidx = (int *)malloc(data_size * sizeof(int));
    tr->pos = (int *)malloc(data_size * sizeof(int));
    
    dsq = (char *)malloc(data_size * sizeof(char));
    for (int i = 0; i < data_size; i++) {
        dsq[i] = rand() % 4; // assuming valid indices into sc
    }

    for (int i = 0; i < 24; i++) {
        sc[i] = rand() % 100;
    }

    for (int i = 0; i < tr->tlen; i++) {
        tr->statetype[i] = (i % 3 == 0) ? 1 : ((i % 5 == 0) ? 3 : 0);
        tr->pos[i] = i % (data_size - 1);
    }

    tpos = 0;
    score = 0;
}