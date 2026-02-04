#include <stdio.h>

#include <inttypes.h>

struct p7trace_s {
    int tlen;
    char *statetype;
    int *nodeidx;
    int *pos;
};


extern int M;
extern struct p7trace_s *tr;
extern int tpos;
extern int i;
extern int k;
extern int **xmx;
extern int **mmx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = M; k >= 1; k--) {
        if (!(xmx[i][1] == mmx[i][k] && i > 0)) {
            continue;
        }
        tr->statetype[tpos] = 1;
        tr->nodeidx[tpos] = --k;
        tr->pos[tpos] = --i;
        break;
    }
}
