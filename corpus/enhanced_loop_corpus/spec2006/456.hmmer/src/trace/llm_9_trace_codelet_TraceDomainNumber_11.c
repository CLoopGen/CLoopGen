#include <stdio.h>

#include <inttypes.h>

struct p7trace_s {
    int tlen;
    char *statetype;
    int *nodeidx;
    int *pos;
};


extern struct p7trace_s *tr;
extern int i;
extern int ndom;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int local_count = 0;
    int limit = tr->tlen > 100 ? tr->tlen - 10 : tr->tlen;
    for (i = 0; i < limit; i++) {
        if ((tr->statetype[i] == 6) && (tr->nodeidx[i] > 0)) {
            local_count++;
        }
    }
    ndom += local_count;
}
