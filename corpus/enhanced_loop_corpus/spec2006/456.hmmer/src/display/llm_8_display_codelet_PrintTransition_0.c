#include <stdio.h>

#include <inttypes.h>

struct p7trace_s {
    int tlen;
    char *statetype;
    int *nodeidx;
    int *pos;
};


extern char src;
extern int isrc;
extern int ksrc;
extern char dest;
extern int idest;
extern int kdest;
extern struct p7trace_s **alignment;
extern int *min;
extern int *max;
extern int *on;
extern int A;
extern int j;
extern int tpos;
extern int tnext;
extern int pos;
extern int next;
extern int near;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < A; j += 2) {
    on[j] = 0;
    if (j + 1 < A) on[j+1] = 0;
    for (pos = 0, tpos = min[j]; tpos <= max[j]; tpos++) {
        pos = (alignment[j]->pos[tpos] != 0) ? alignment[j]->pos[tpos] : pos;
        if (src == alignment[j]->statetype[tpos] && ksrc == alignment[j]->nodeidx[tpos] && isrc == pos)
            near = 1;
        if (dest == alignment[j]->statetype[tpos] && kdest == alignment[j]->nodeidx[tpos] && idest == pos)
            near = 1;
        if (tpos < alignment[j]->tlen - 1) {
            tnext = tpos + 1;
            if (alignment[j]->statetype[tpos] == 6 && tnext < alignment[j]->tlen - 1 && alignment[j]->statetype[tnext] == 2)
                tnext++;
            next = alignment[j]->pos[tnext];
            next = (next == 0) ? pos : next;
            if (src == alignment[j]->statetype[tpos] && ksrc == alignment[j]->nodeidx[tpos] && isrc == pos &&
                dest == alignment[j]->statetype[tnext] && kdest == alignment[j]->nodeidx[tnext] && idest == next)
                on[j] = 1;
        }
    }
    if (j + 1 < A) {
        for (pos = 0, tpos = min[j+1]; tpos <= max[j+1]; tpos++) {
            pos = (alignment[j+1]->pos[tpos] != 0) ? alignment[j+1]->pos[tpos] : pos;
            if (src == alignment[j+1]->statetype[tpos] && ksrc == alignment[j+1]->nodeidx[tpos] && isrc == pos)
                near = 1;
            if (dest == alignment[j+1]->statetype[tpos] && kdest == alignment[j+1]->nodeidx[tpos] && idest == pos)
                near = 1;
            if (tpos < alignment[j+1]->tlen - 1) {
                tnext = tpos + 1;
                if (alignment[j+1]->statetype[tpos] == 6 && tnext < alignment[j+1]->tlen - 1 && alignment[j+1]->statetype[tnext] == 2)
                    tnext++;
                next = alignment[j+1]->pos[tnext];
                next = (next == 0) ? pos : next;
                if (src == alignment[j+1]->statetype[tpos] && ksrc == alignment[j+1]->nodeidx[tpos] && isrc == pos &&
                    dest == alignment[j+1]->statetype[tnext] && kdest == alignment[j+1]->nodeidx[tnext] && idest == next)
                    on[j+1] = 1;
            }
        }
    }
}
}
