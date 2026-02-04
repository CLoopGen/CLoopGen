#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

struct p7trace_s {
    int tlen;
    char *statetype;
    int *nodeidx;
    int *pos;
};

int n1;
struct p7trace_s **t2;
int n2;
struct p7trace_s **tr;
int i;

void init_vars() {
    n1 = 0;
    n2 = 65536; 

    t2 = (struct p7trace_s **)calloc(n2, sizeof(struct p7trace_s *));
    tr = (struct p7trace_s **)calloc(n1 + n2, sizeof(struct p7trace_s *));

    for (int idx = 0; idx < n2; idx++) {
        struct p7trace_s *trace = (struct p7trace_s *)malloc(sizeof(struct p7trace_s));
        trace->tlen = idx % 100;
        trace->statetype = (char *)malloc(16);
        for (int j = 0; j < 15; j++)
            trace->statetype[j] = 'A' + (idx + j) % 26;
        trace->statetype[15] = '\0';

        trace->nodeidx = (int *)malloc(10 * sizeof(int));
        trace->pos = (int *)malloc(10 * sizeof(int));
        for (int j = 0; j < 10; j++) {
            trace->nodeidx[j] = idx * 10 + j;
            trace->pos[j] = (idx + 1) * (j + 1);
        }

        t2[idx] = trace;
    }
}