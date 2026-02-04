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
    int temp_i1 = -1;
    int temp_k1 = k1;
    int found = 0;
    for (tpos = 0; tpos < tr->tlen && !found; tpos++) {
        char st = tr->statetype[tpos];
        int ni = tr->nodeidx[tpos];
        if (temp_k1 == -1 && (st == 1 || st == 2)) {
            temp_k1 = ni;
        }
        if (st == 1) {
            temp_i1 = tr->pos[tpos];
            found = 1;
        }
    }
    if (temp_k1 != k1) {
        k1 = temp_k1;
    }
    if (temp_i1 != -1) {
        i1 = temp_i1;
    }
}
