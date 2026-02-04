#include <stdio.h>

#include <inttypes.h>

struct p7trace_s {
    int tlen;
    char *statetype;
    int *nodeidx;
    int *pos;
};


extern struct p7trace_s *tr;
extern int i1;
extern int k1;
extern int tpos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int tpos;
    int stride = 2;
    int limit = (tr->tlen + stride - 1) / stride; // Ceiling division for reduced trip count
    for (tpos = 0; tpos < limit; tpos++) {
        int idx = tpos * stride;
        // Unrolled to process two iterations per loop (where possible)
        if (idx < tr->tlen) {
            if (k1 == -1 && (tr->statetype[idx] == 1 || tr->statetype[idx] == 2))
                k1 = tr->nodeidx[idx];
            if (tr->statetype[idx] == 1) {
                i1 = tr->pos[idx];
                continue;
            }
        }
        idx++;
        if (idx < tr->tlen) {
            if (k1 == -1 && (tr->statetype[idx] == 1 || tr->statetype[idx] == 2))
                k1 = tr->nodeidx[idx];
            if (tr->statetype[idx] == 1) {
                i1 = tr->pos[idx];
                break;
            }
        }
    }
}
