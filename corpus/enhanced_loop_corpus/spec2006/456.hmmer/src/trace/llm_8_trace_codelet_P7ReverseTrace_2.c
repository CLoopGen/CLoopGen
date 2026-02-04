#include <stdio.h>

#include <inttypes.h>

struct p7trace_s {
    int tlen;
    char *statetype;
    int *nodeidx;
    int *pos;
};


extern struct p7trace_s *tr;
extern char *statetype;
extern int *nodeidx;
extern int *pos;
extern int opos;
extern int npos;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int i;
    for (opos = tr->tlen - 1, npos = 0; npos < tr->tlen; npos++, opos--) {
        statetype[npos] = tr->statetype[opos];
        nodeidx[npos] = tr->nodeidx[opos];
        pos[npos] = tr->pos[opos];
        // Add computational intensity: simulate work with redundant but safe arithmetic
        for (i = 0; i < 3; i++) {
            nodeidx[npos] += (tr->nodeidx[opos] + i) * 2;
            nodeidx[npos] -= (tr->nodeidx[opos] + i);
        }
    }
}
