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
    score = 0;
    for (int i = 0; i < tr->tlen; i++) {
        int condition = (tr->statetype[i] == 1 || tr->statetype[i] == 3);
        int pos_val = tr->pos[i];
        int dsq_val = (int)dsq[pos_val];
        if (condition) {
            score += sc[dsq_val];  // Introduce WAW dependency on 'score' with unrolled-like accumulation
        }
    }
}
