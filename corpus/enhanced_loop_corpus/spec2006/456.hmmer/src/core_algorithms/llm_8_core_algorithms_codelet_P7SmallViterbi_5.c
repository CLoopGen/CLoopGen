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
    int base_pos = ctr->pos[i * 2 + 1];
    int start_fill = ctr->pos[i * 2 + 2] + 1;
    int end_fill = (i + 1 < ndom) ? ctr->pos[(i + 1) * 2 + 1] : start_fill;

    for (t2 = 2; t2 < tarr[i]->tlen - 2; t2 += 2) {
        tr->statetype[tpos] = tarr[i]->statetype[t2];
        tr->nodeidx[tpos] = tarr[i]->nodeidx[t2];
        if (tarr[i]->pos[t2] > 0)
            tr->pos[tpos] = tarr[i]->pos[t2] + base_pos;
        else
            tr->pos[tpos] = 0;
        tpos++;

        if (t2 + 1 < tarr[i]->tlen - 2) {
            tr->statetype[tpos] = tarr[i]->statetype[t2 + 1];
            tr->nodeidx[tpos] = tarr[i]->nodeidx[t2 + 1];
            if (tarr[i]->pos[t2 + 1] > 0)
                tr->pos[tpos] = tarr[i]->pos[t2 + 1] + base_pos;
            else
                tr->pos[tpos] = 0;
            tpos++;
        }
    }

    tr->statetype[tpos] = (i == ndom - 1) ? 8 : 10;
    tr->nodeidx[tpos] = 0;
    tr->pos[tpos] = 0;
    tpos++;

    if (i != ndom - 1 && start_fill <= end_fill) {
        int fill_count = end_fill - start_fill + 1;
        for (int f = 0; f < fill_count; f++) {
            tr->statetype[tpos] = 10;
            tr->nodeidx[tpos] = 0;
            tr->pos[tpos] = start_fill + f;
            tpos++;
        }
    }
}
}
