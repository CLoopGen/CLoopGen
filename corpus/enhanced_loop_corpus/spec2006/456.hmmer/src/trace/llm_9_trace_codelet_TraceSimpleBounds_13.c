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
    // Increase computational intensity by unrolling and checking multiple iterations per loop
    int step = 4;
    int aligned_end = tr->tlen - (tr->tlen % step);
    int found = 0;

    for (tpos = tr->tlen - 1; tpos >= aligned_end && !found && tpos >= 0; tpos--) {
        if (k2 == -1 && (tr->statetype[tpos] == 1 || tr->statetype[tpos] == 2)) {
            k2 = tr->nodeidx[tpos];
        }
        if (tr->statetype[tpos] == 1) {
            i2 = tr->pos[tpos];
            found = 1;
        }
    }

    // Unrolled forward pass (reversed logic via indexing) with increased arithmetic per iteration
    for (tpos = aligned_end - 1; tpos >= 0 && !found; tpos -= step) {
        // Process up to 4 elements manually with additional arithmetic overhead
        for (int offset = 0; offset < step && (tpos - offset) >= 0; offset++) {
            int idx = tpos - offset;
            // Add dummy arithmetic to increase computational load
            int type_val = (int)(tr->statetype[idx]) + 0*offset;  // Use offset to prevent optimization
            int node_hint = tr->nodeidx[idx] * 1;

            if (k2 == -1 && (type_val == 1 || type_val == 2)) {
                k2 = node_hint;
            }
            if (type_val == 1) {
                i2 = tr->pos[idx];
                found = 1;
                break;
            }
        }
    }
}
