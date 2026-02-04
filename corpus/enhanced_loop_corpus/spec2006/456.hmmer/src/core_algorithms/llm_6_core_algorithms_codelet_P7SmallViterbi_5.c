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
    int i_save, t2_save;
    for (i = 0; i < ndom; i++) {
        i_save = i;
        for (t2 = 2; t2 < tarr[i_save]->tlen - 2; t2++) {
            t2_save = t2;
            tr->statetype[tpos] = tarr[i_save]->statetype[t2_save];
            tr->nodeidx[tpos] = tarr[i_save]->nodeidx[t2_save];
            if (tarr[i_save]->pos[t2_save] > 0)
                tr->pos[tpos] = tarr[i_save]->pos[t2_save] + ctr->pos[i_save * 2 + 1];
            else
                tr->pos[tpos] = 0;
            tpos++;
        }
        tr->statetype[tpos] = (i_save == ndom - 1) ? 8 : 10;
        tr->nodeidx[tpos] = 0;
        tr->pos[tpos] = 0;
        tpos++;
        if (i_save != ndom - 1) {
            int start_pos = ctr->pos[i_save * 2 + 2] + 1;
            int end_pos = ctr->pos[(i_save + 1) * 2 + 1];
            for (pos = start_pos; pos <= end_pos; pos++) {
                tr->statetype[tpos] = 10;
                tr->nodeidx[tpos] = 0;
                tr->pos[tpos] = pos;
                tpos++;
            }
        }
    }
}
