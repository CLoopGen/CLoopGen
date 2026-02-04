#include <stdio.h>

#include <inttypes.h>

struct p7trace_s {
    int tlen;
    char *statetype;
    int *nodeidx;
    int *pos;
};


extern struct p7trace_s *tr;
extern int i1;
extern int k1;
extern int tpos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int tpos;
    for (tpos = 0; tpos < tr->tlen && k1 == -1; tpos++) {
        if (tr->statetype[tpos] == 1 || tr->statetype[tpos] == 2) {
            k1 = tr->nodeidx[tpos];
        }
        if (tr->statetype[tpos] == 1) {
            i1 = tr->pos[tpos];
            break;
        }
    }
}
