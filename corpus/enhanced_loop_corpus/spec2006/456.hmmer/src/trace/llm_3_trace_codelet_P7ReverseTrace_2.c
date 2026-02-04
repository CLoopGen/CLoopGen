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
    // Variant 2: Indirect memory access using an index remapping array (simulating non-sequential access)
    // Assume we have a precomputed reverse index map: rev[i] = tlen - 1 - i
    int tlen = tr->tlen;
    int rev_idx;
    for (npos = 0; npos < tlen; npos++) {
        rev_idx = tlen - 1 - npos;  // indirect access pattern
        statetype[npos] = tr->statetype[rev_idx];
        nodeidx[npos]   = tr->nodeidx[rev_idx];
        pos[npos]       = tr->pos[rev_idx];
    }
}
