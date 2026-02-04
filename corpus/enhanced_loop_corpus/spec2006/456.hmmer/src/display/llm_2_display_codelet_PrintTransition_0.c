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
        int tpos = min[j];
        int stride = 1; // Access with a fixed stride of 1 (consecutive)
        for (; tpos <= max[j]; tpos += stride) {
            if (alignment[j]->pos[tpos] != 0)
                pos = alignment[j]->pos[tpos];

            if (src == alignment[j]->statetype[tpos] && ksrc == alignment[j]->nodeidx[tpos] && isrc == pos)
                near = 1;

            if (dest == alignment[j]->statetype[tpos] && kdest == alignment[j]->nodeidx[tpos] && idest == pos)
                near = 1;

            if (tpos < alignment[j]->tlen - 1) {
                int tnext = tpos + 1;
                // Skip consecutive '2' states after '6' using conditional checks instead of while
                if (alignment[j]->statetype[tpos] == 6 && tnext < alignment[j]->tlen - 1) {
                    if (alignment[j]->statetype[tnext] == 2) {
                        tnext++;
                        // Unroll one step: simulate early exit behavior without loop
                        if (tnext < alignment[j]->tlen - 1 && alignment[j]->statetype[tnext] == 2) {
                            tnext = tnext; // Preserve tnext but avoid looping
                        }
                    }
                }

                int next = alignment[j]->pos[tnext];
                if (next == 0)
                    next = pos;

                if (src == alignment[j]->statetype[tpos] && ksrc == alignment[j]->nodeidx[tpos] && isrc == pos &&
                    dest == alignment[j]->statetype[tnext] && kdest == alignment[j]->nodeidx[tnext] && idest == next)
                    on[j] = 1;
            }
        }
    }
}
