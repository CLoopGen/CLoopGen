#include <stdio.h>

#include <inttypes.h>

struct p7trace_s {
    int tlen;
    char *statetype;
    int *nodeidx;
    int *pos;
};


extern struct p7trace_s *ctr;
extern struct p7trace_s *tr;
extern int pos;
extern int tpos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int base_tpos = tpos;
    for (pos = 1; pos <= ctr->pos[1]; pos++) {
        int offset = pos - 1;
        tr->statetype[base_tpos + offset] = 5;
        tr->nodeidx[base_tpos + offset] = 0;
        tr->pos[base_tpos + offset] = pos;
    }
    tpos += ctr->pos[1];
}
