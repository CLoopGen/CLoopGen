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



void loop() {
    for (int j = 0; j < A; j++) {
        on[j] = 0;
        int pos = 0;
        // Use indirect access via an index map (simulated with linear scan and conditionals)
        for (int idx = 0; idx <= max[j] - min[j]; idx++) {
            int tpos = min[j] + idx; // Indirect-like indexing pattern

            if (tpos > max[j]) continue;

            if (alignment[j]->pos[tpos] != 0)
                pos = alignment[j]->pos[tpos];

            if (src == alignment[j]->statetype[tpos] && ksrc == alignment[j]->nodeidx[tpos] && isrc == pos)
                near = 1;

            if (dest == alignment[j]->statetype[tpos] && kdest == alignment[j]->nodeidx[tpos] && idest == pos)
                near = 1;

            if (tpos < alignment[j]->tlen - 1) {
                int tnext = tpos + 1;

                // Replace while loop: check up to two ahead to mimic skipping strided '2' after '6'
                if (alignment[j]->statetype[tpos] == 6) {
                    if (tnext < alignment[j]->tlen - 1 && alignment[j]->statetype[tnext] == 2) {
                        tnext++;
                        // One additional skip to simulate multi-step traversal without loops
                        if (tnext < alignment[j]->tlen - 1 && alignment[j]->statetype[tnext] == 2) {
                            tnext++;
                        }
                    }
                }

                int next = (tnext < alignment[j]->tlen) ? alignment[j]->pos[tnext] : 0;
                if (next == 0)
                    next = pos;

                if (tpos + 1 < alignment[j]->tlen && 
                    src == alignment[j]->statetype[tpos] && ksrc == alignment[j]->nodeidx[tpos] && isrc == pos &&
                    dest == alignment[j]->statetype[tnext] && kdest == alignment[j]->nodeidx[tnext] && idest == next)
                    on[j] = 1;
            }
        }
    }
}
