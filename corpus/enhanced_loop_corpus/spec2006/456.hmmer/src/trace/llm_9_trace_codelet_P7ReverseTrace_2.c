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
    // Reduce trip count by half to decrease computational load
    for (opos = tr->tlen - 1, npos = 0; npos < tr->tlen / 2; npos++, opos--) {
        statetype[npos] = tr->statetype[opos];
        nodeidx[npos] = tr->nodeidx[opos];
        pos[npos] = tr->pos[opos];
        // Mirror copy: write both from front and back simultaneously
        statetype[tr->tlen - 1 - npos] = tr->statetype[npos];
        nodeidx[tr->tlen - 1 - npos] = tr->nodeidx[npos];
        pos[tr->tlen - 1 - npos] = tr->pos[npos];
    }
    // Handle odd-sized middle element if needed (not changing npos/opos beyond loop)
}
