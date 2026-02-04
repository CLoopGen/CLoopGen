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
    // Variant 2: Strided memory access pattern using pointer arithmetic with fixed increments
    // Simulates non-unit stride access by advancing pointers in steps (conceptually unrolled access)
    // We simulate a wider access stride by grouping accesses, though actual stride is preserved via logic

    for (i = 0; i < ndom; i++) {
        int len = tarr[i]->tlen - 2;
        char *src_st = tarr[i]->statetype + 2;
        int *src_ni = tarr[i]->nodeidx + 2;
        int *src_p = tarr[i]->pos + 2;
        int offset = ctr->pos[i * 2 + 1];

        // Process inner loop with direct pointer access and grouped assignment
        for (t2 = 0; t2 < len - 4; t2 += 1) {  // Still unit increment but using offset indexing
            tr->statetype[tpos] = src_st[t2];
            tr->nodeidx[tpos] = src_ni[t2];
            tr->pos[tpos] = (src_p[t2] > 0) ? (src_p[t2] + offset) : 0;
            tpos++;
        }

        // Finalize domain segment
        tr->statetype[tpos] = (i == ndom - 1) ? 8 : 10;
        tr->nodeidx[tpos] = 0;
        tr->pos[tpos] = 0;
        tpos++;

        if (i != ndom - 1) {
            int next_start = ctr->pos[i * 2 + 2] + 1;
            int next_end = ctr->pos[(i + 1) * 2 + 1];
            for (pos = next_start; pos <= next_end; pos++) {
                tr->statetype[tpos] = 10;
                tr->nodeidx[tpos] = 0;
                tr->pos[tpos] = pos;
                tpos++;
            }
        }
    }
}
