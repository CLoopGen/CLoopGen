#include <stdio.h>

#include <inttypes.h>

struct p7trace_s {
    int tlen;
    char *statetype;
    int *nodeidx;
    int *pos;
};


extern struct p7trace_s *ctr;
extern struct p7trace_s *tr;
extern struct p7trace_s **tarr;
extern int ndom;
extern int i;
extern int pos;
extern int tpos;
extern int t2;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Consecutive memory access with local caching for improved spatial locality
    int i_cache, t2_cache;
    char *stype_cache;
    int *nidx_cache, *pos_cache;
    int cpos1, cpos2;

    for (i = 0; i < ndom; i++) {
        stype_cache = tarr[i]->statetype;
        nidx_cache = tarr[i]->nodeidx;
        pos_cache = tarr[i]->pos;
        cpos1 = i * 2 + 1;
        cpos2 = i * 2 + 2;

        for (t2 = 2; t2 < tarr[i]->tlen - 2; t2++) {
            tr->statetype[tpos] = stype_cache[t2];
            tr->nodeidx[tpos] = nidx_cache[t2];
            if (pos_cache[t2] > 0)
                tr->pos[tpos] = pos_cache[t2] + ctr->pos[cpos1];
            else
                tr->pos[tpos] = 0;
            tpos++;
        }

        tr->statetype[tpos] = (i == ndom - 1) ? 8 : 10;
        tr->nodeidx[tpos] = 0;
        tr->pos[tpos] = 0;
        tpos++;

        if (i != ndom - 1) {
            int start = ctr->pos[cpos2] + 1;
            int end = ctr->pos[(i + 1) * 2 + 1];
            for (pos = start; pos <= end; pos++) {
                tr->statetype[tpos] = 10;
                tr->nodeidx[tpos] = 0;
                tr->pos[tpos] = pos;
                tpos++;
            }
        }
    }
}
