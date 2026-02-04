#include <stdio.h>

#include <inttypes.h>

struct p7trace_s {
    int tlen;
    char *statetype;
    int *nodeidx;
    int *pos;
};


extern struct p7trace_s *tr;
extern int i2;
extern int k2;
extern int tpos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (tpos = tr->tlen - 1; tpos >= 0; tpos--) {
        if (tr->statetype[tpos] != 1 && tr->statetype[tpos] != 2) 
            continue;
        if (k2 == -1 && (tr->statetype[tpos] == 1 || tr->statetype[tpos] == 2))
            k2 = tr->nodeidx[tpos];
        if (tr->statetype[tpos] == 1) {
            i2 = tr->pos[tpos];
            break;
        }
    }
}
