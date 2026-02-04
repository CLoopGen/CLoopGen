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
    for (tpos = 0; tpos < tr->tlen; tpos++) {
        int condition_met = (tr->statetype[tpos] == 1 || tr->statetype[tpos] == 3);
        if (condition_met) {
            score += sc[(int)dsq[tr->pos[tpos]]];
        } else {
            // Explicitly do nothing, maintaining control flow clarity
        }
    }
}
