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
    int temp_i2 = -1;
    int temp_k2 = k2;

    for (tpos = tr->tlen - 1; tpos >= 0; tpos--) {
        char state = tr->statetype[tpos];
        int node_val = tr->nodeidx[tpos];

        if (temp_k2 == -1 && (state == 1 || state == 2)) {
            temp_k2 = node_val;
        }
        if (state == 1) {
            temp_i2 = tr->pos[tpos];
        }
    }

    if (temp_i2 != -1) {
        i2 = temp_i2;
    }
    k2 = temp_k2;
}
