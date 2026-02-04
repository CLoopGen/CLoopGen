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



void loop() {
    int local_i2 = i2;
    int local_k2 = k2;
    int updated = 0;

    for (tpos = tr->tlen - 1; tpos >= 0 && !updated; tpos--) {
        char st = tr->statetype[tpos];

        if (local_k2 == -1 && (st == 1 || st == 2)) {
            local_k2 = tr->nodeidx[tpos];
        }
        if (st == 1) {
            local_i2 = tr->pos[tpos];
            updated = 1;
        }
    }

    i2 = local_i2;
    k2 = local_k2;
}
