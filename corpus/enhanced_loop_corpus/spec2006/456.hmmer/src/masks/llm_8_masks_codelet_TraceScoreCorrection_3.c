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



void loop(){
    int i;
    for (tpos = 0; tpos < tr->tlen; tpos += 2) {
        if (tr->statetype[tpos] == 1 || tr->statetype[tpos] == 3) {
            score += sc[(int)dsq[tr->pos[tpos]]];
        }
        if (tpos + 1 < tr->tlen) {
            if (tr->statetype[tpos + 1] == 1 || tr->statetype[tpos + 1] == 3) {
                score += sc[(int)dsq[tr->pos[tpos + 1]]];
            }
        }
    }
}
