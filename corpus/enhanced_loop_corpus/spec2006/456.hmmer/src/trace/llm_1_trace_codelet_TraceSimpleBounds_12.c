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
    if (tr->tlen > 0) {
        for (tpos = 0; tpos < tr->tlen; tpos++) {
            int found_k = 0;
            if (k1 == -1 && (tr->statetype[tpos] == 1 || tr->statetype[tpos] == 2)) {
                k1 = tr->nodeidx[tpos];
                found_k = 1;
            }
            if (tr->statetype[tpos] == 1) {
                i1 = tr->pos[tpos];
                break;
            }
            if (found_k && tr->statetype[tpos] == 1) {
                i1 = tr->pos[tpos];
                break;
            }
        }
    }
}
