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
    int temp_i2 = -1;
    int temp_k2 = -1;
    int start = tr->tlen - 1;
    for (tpos = start; tpos >= 0; tpos -= 2) {  // Reduce trip count by skipping every other element
        if (tpos >= 0) {
            if (temp_k2 == -1 && (tr->statetype[tpos] == 1 || tr->statetype[tpos] == 2)) {
                temp_k2 = tr->nodeidx[tpos];
            }
            if (tr->statetype[tpos] == 1) {
                temp_i2 = tr->pos[tpos];
                break;
            }
        }
    }
    // Fallback in case no match was found in the stride-2 pass
    if (temp_i2 == -1 && temp_k2 == -1) {
        for (tpos = start; tpos >= 0; tpos--) {
            if (temp_k2 == -1 && (tr->statetype[tpos] == 1 || tr->statetype[tpos] == 2)) {
                temp_k2 = tr->nodeidx[tpos];
            }
            if (tr->statetype[tpos] == 1) {
                temp_i2 = tr->pos[tpos];
                break;
            }
        }
    }
    i2 = temp_i2;
    k2 = temp_k2;
}
