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
for (i = 0; i < ndom; i++) {
    if (tarr[i]->tlen > 4) {
        for (t2 = 2; t2 < tarr[i]->tlen - 2; t2++) {
            tr->statetype[tpos] = tarr[i]->statetype[t2];
            tr->nodeidx[tpos] = tarr[i]->nodeidx[t2];
            if (tarr[i]->pos[t2] > 0)
                tr->pos[tpos] = tarr[i]->pos[t2] + ctr->pos[i * 2 + 1];
            else
                tr->pos[tpos] = 0;
            tpos++;
        }
    }
    tr->statetype[tpos] = (i == ndom - 1) ? 8 : 10;
    tr->nodeidx[tpos] = 0;
    tr->pos[tpos] = 0;
    tpos++;
    if (i != ndom - 1) {
        int start = ctr->pos[i * 2 + 2] + 1;
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
