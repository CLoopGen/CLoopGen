#include <stdio.h>

#include <inttypes.h>

struct p7trace_s {
    int tlen;
    char *statetype;
    int *nodeidx;
    int *pos;
};


extern struct p7trace_s *tr;
extern char *dsq;
extern int sc[24];
extern int tpos;
extern int score;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access pattern
    // Instead of sequential tpos++, we process every 2nd element in two passes: even and odd indices.
    // This creates a strided access pattern on tr->statetype and tr->pos arrays.
    int tlen = tr->tlen;
    for (tpos = 0; tpos < tlen; tpos += 2)
        if (tr->statetype[tpos] == 1 || tr->statetype[tpos] == 3)
            score += sc[(int)dsq[tr->pos[tpos]]];

    for (tpos = 1; tpos < tlen; tpos += 2)
        if (tr->statetype[tpos] == 1 || tr->statetype[tpos] == 3)
            score += sc[(int)dsq[tr->pos[tpos]]];
}
