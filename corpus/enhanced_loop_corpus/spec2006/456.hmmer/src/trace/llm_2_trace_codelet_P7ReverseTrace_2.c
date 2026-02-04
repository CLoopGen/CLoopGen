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
    // Variant 1: Strided memory access with stride of 2, unrolling the loop to handle two elements per iteration
    int tlen = tr->tlen;
    for (opos = tlen - 1, npos = 0; npos + 1 < tlen; npos += 2, opos -= 2) {
        statetype[npos]     = tr->statetype[opos];
        nodeidx[npos]       = tr->nodeidx[opos];
        pos[npos]           = tr->pos[opos];

        statetype[npos + 1] = tr->statetype[opos - 1];
        nodeidx[npos + 1]   = tr->nodeidx[opos - 1];
        pos[npos + 1]       = tr->pos[opos - 1];
    }
    // Handle odd-sized array remainder
    if (npos < tlen) {
        statetype[npos] = tr->statetype[opos];
        nodeidx[npos]   = tr->nodeidx[opos];
        pos[npos]       = tr->pos[opos];
    }
}
