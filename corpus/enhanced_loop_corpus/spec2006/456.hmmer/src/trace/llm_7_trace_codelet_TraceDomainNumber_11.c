#include <stdio.h>

#include <inttypes.h>

struct p7trace_s {
    int tlen;
    char *statetype;
    int *nodeidx;
    int *pos;
};


extern struct p7trace_s *tr;
extern int i;
extern int ndom;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_ndom = ndom;
    for (i = 0; i < tr->tlen; i++) {
        int idx = tr->nodeidx != NULL ? tr->nodeidx[i] : 0;
        if (tr->statetype[i] == 6 && (idx > 0 || tr->pos[i] > 0)) {
            local_ndom++;
        }
    }
    ndom = local_ndom;
}
