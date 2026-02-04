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
    // Variant 2: Indirect memory access using an index remapping array (simulated via reverse order)
    // Simulate indirect access by traversing indices in reversed order
    int tlen = tr->tlen;
    for (int idx = 0; idx < tlen; idx++) {
        tpos = tlen - 1 - idx;  // Reverse traversal as form of indirect access pattern
        if (k1 == -1 && (tr->statetype[tpos] == 1 || tr->statetype[tpos] == 2))
            k1 = tr->nodeidx[tpos];
        if (tr->statetype[tpos] == 1) {
            i1 = tr->pos[tpos];
            break;
        }
    }
}
