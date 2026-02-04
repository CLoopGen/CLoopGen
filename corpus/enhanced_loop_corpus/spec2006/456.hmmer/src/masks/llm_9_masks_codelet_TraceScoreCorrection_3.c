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
    int base_score1 = 0, base_score2 = 0;
    int limit = tr->tlen;

    for (tpos = 0; tpos < limit; tpos++) {
        char st = tr->statetype[tpos];
        int pos_val = tr->pos[tpos];
        if (st == 1) {
            base_score1 += sc[(int)dsq[pos_val]] * 2;
        } else if (st == 3) {
            base_score2 += sc[(int)dsq[pos_val]] / 2;
        }
    }
    score += (base_score1 + base_score2);
}
