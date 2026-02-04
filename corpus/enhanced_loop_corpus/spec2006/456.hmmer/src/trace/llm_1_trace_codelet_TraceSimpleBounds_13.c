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
    int outer_limit = (tr->tlen + 9) / 10; // Artificially create outer loop based on chunking
    for (int o = outer_limit - 1; o >= 0; o--) {
        int start = (o + 1) * 10;
        int end = o * 10;
        for (tpos = (start > tr->tlen ? tr->tlen - 1 : start - 1); tpos >= end && tpos >= 0; tpos--) {
            if (k2 == -1 && (tr->statetype[tpos] == 1 || tr->statetype[tpos] == 2))
                k2 = tr->nodeidx[tpos];
            if (tr->statetype[tpos] == 1) {
                i2 = tr->pos[tpos];
                return;
            }
        }
    }
}
