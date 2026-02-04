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
    // Variant 1: Memory Access Pattern Modification - Strided access (step by 2, then handle remainder)
    int tlen = tr->tlen;
    int stride = 2;
    
    // First pass: strided backward traversal (even indices in reverse)
    for (tpos = tlen - 1; tpos >= 0; tpos -= stride) {
        if (k2 == -1 && (tr->statetype[tpos] == 1 || tr->statetype[tpos] == 2))
            k2 = tr->nodeidx[tpos];
        if (tr->statetype[tpos] == 1) {
            i2 = tr->pos[tpos];
            break;
        }
    }
    
    // Second pass: handle odd indices if not already found and if needed
    if (i2 == -1 || k2 == -1) {
        for (tpos = tlen - 2; tpos >= 0; tpos -= stride) {
            if (k2 == -1 && (tr->statetype[tpos] == 1 || tr->statetype[tpos] == 2))
                k2 = tr->nodeidx[tpos];
            if (tr->statetype[tpos] == 1) {
                i2 = tr->pos[tpos];
                break;
            }
        }
    }
}
