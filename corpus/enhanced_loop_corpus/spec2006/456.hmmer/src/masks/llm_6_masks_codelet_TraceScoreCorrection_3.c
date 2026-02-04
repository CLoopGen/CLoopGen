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
    int temp_score = 0;
    for (int i = 0; i < tr->tlen; i++) {
        if (tr->statetype[i] == 1 || tr->statetype[i] == 3) {
            temp_score += sc[(int)dsq[tr->pos[i]]];
        }
    }
    score = temp_score;
}
