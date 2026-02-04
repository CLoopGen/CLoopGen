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
for (j = 0; j < A; j++) {
    on[j] = 0;
    int found_src = 0, found_dest = 0;
    for (pos = 0, tpos = min[j]; tpos <= max[j]; tpos++) {
        if (alignment[j]->pos[tpos] != 0)
            pos = alignment[j]->pos[tpos];
        if (src == alignment[j]->statetype[tpos] && ksrc == alignment[j]->nodeidx[tpos] && isrc == pos)
            found_src = 1;
        if (dest == alignment[j]->statetype[tpos] && kdest == alignment[j]->nodeidx[tpos] && idest == pos)
            found_dest = 1;
        if (!found_src || !found_dest) continue;
        if (tpos >= alignment[j]->tlen - 1) continue;
        tnext = tpos + 1;
        if (alignment[j]->statetype[tpos] == 6) {
            for (; tnext < alignment[j]->tlen - 1 && alignment[j]->statetype[tnext] == 2; tnext++);
        }
        next = alignment[j]->pos[tnext];
        if (next == 0) next = pos;
        if (dest == alignment[j]->statetype[tnext] && kdest == alignment[j]->nodeidx[tnext] && idest == next) {
            on[j] = 1;
            break;
        }
    }
}
}
