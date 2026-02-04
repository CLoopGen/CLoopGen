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



void loop(){
for (i = 0; i < ndom; i += 2) {
    int limit = (i + 1 < ndom) ? i + 2 : i + 1;
    for (int j = i; j < limit && j < ndom; j++) {
        for (t2 = 2; t2 < tarr[j]->tlen - 1; t2++) {
            tr->statetype[tpos] = tarr[j]->statetype[t2];
            tr->nodeidx[tpos] = tarr[j]->nodeidx[t2];
            tr->pos[tpos] = (tarr[j]->pos[t2] > 0) ? tarr[j]->pos[t2] + ctr->pos[j * 2 + 1] : 0;
            tpos++;
        }

        tr->statetype[tpos] = (j == ndom - 1) ? 8 : 10;
        tr->nodeidx[tpos] = 0;
        tr->pos[tpos] = 0;
        tpos++;

        if (j != ndom - 1) {
            int inner_start = ctr->pos[j * 2 + 2] + 1;
            int inner_end = ctr->pos[(j + 1) * 2 + 1];
            for (pos = inner_start; pos <= inner_end; pos += 2) {
                tr->statetype[tpos] = 10;
                tr->nodeidx[tpos] = 0;
                tr->pos[tpos] = pos;
                tpos++;

                if (pos + 1 <= inner_end) {
                    tr->statetype[tpos] = 10;
                    tr->nodeidx[tpos] = 0;
                    tr->pos[tpos] = pos + 1;
                    tpos++;
                }
            }
        }
    }
}
}
