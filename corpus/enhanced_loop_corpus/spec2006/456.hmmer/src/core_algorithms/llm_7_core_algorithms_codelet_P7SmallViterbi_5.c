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
    int temp_statetype, temp_nodeidx, temp_pos;
    int base_offset, next_base_offset;

    for (i = 0; i < ndom; i++) {
        base_offset = i * 2 + 1;
        next_base_offset = (i + 1) * 2 + 1;

        for (t2 = 2; t2 < tarr[i]->tlen - 2; t2++) {
            temp_statetype = tarr[i]->statetype[t2];
            temp_nodeidx = tarr[i]->nodeidx[t2];
            temp_pos = (tarr[i]->pos[t2] > 0) ? tarr[i]->pos[t2] + ctr->pos[base_offset] : 0;

            tr->statetype[tpos] = temp_statetype;
            tr->nodeidx[tpos] = temp_nodeidx;
            tr->pos[tpos] = temp_pos;
            tpos++;
        }

        tr->statetype[tpos] = (i == ndom - 1) ? 8 : 10;
        tr->nodeidx[tpos] = 0;
        tr->pos[tpos] = 0;
        tpos++;

        if (i != ndom - 1) {
            for (pos = ctr->pos[i * 2 + 2] + 1; pos <= ctr->pos[next_base_offset]; pos++) {
                tr->statetype[tpos] = 10;
                tr->nodeidx[tpos] = 0;
                tr->pos[tpos] = pos;
                tpos++;
            }
        }
    }
}
