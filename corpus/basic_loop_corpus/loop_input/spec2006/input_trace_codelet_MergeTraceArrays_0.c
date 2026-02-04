#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

struct p7trace_s {
    int tlen;
    char *statetype;
    int *nodeidx;
    int *pos;
};

struct p7trace_s **t1;
int n1 = 65536;
struct p7trace_s **tr;
int i;

void init_vars() {
    n1 = 65536;
    t1 = (struct p7trace_s **)calloc(n1, sizeof(struct p7trace_s *));
    tr = (struct p7trace_s **)calloc(n1, sizeof(struct p7trace_s *));

    for (int idx = 0; idx < n1; idx++) {
        struct p7trace_s *pt = (struct p7trace_s *)malloc(sizeof(struct p7trace_s));
        pt->tlen = idx % 1000;
        pt->statetype = (char *)malloc(16);
        for (int j = 0; j < 15; j++)
            pt->statetype[j] = 'A' + (idx + j) % 26;
        pt->statetype[15] = '\0';

        pt->nodeidx = (int *)malloc(100 * sizeof(int));
        pt->pos = (int *)malloc(100 * sizeof(int));
        for (int j = 0; j < 100; j++) {
            pt->nodeidx[j] = j;
            pt->pos[j] = idx + j;
        }

        t1[idx] = pt;
    }
}