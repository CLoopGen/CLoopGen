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
    // Variant 1: Strided memory access (stride of 2) with forward traversal
    int tlen = tr->tlen;
    for (tpos = 0; tpos < tlen; tpos += 2) {
        if (k1 == -1 && (tr->statetype[tpos] == 1 || tr->statetype[tpos] == 2))
            k1 = tr->nodeidx[tpos];
        if (tr->statetype[tpos] == 1) {
            i1 = tr->pos[tpos];
            break;
        }
    }
    // Handle odd-length case by checking last element if missed due to stride
    if ((tlen % 2 == 1) && (k1 == -1 || i1 == 0)) {
        tpos = tlen - 1;
        if (k1 == -1 && (tr->statetype[tpos] == 1 || tr->statetype[tpos] == 2))
            k1 = tr->nodeidx[tpos];
        if (tr->statetype[tpos] == 1)
            i1 = tr->pos[tpos];
    }
}
