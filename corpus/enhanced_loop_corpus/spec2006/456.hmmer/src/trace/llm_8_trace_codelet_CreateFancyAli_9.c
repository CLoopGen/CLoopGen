#include <stdio.h>

#include <inttypes.h>

struct p7trace_s {
    int tlen;
    char *statetype;
    int *nodeidx;
    int *pos;
};


struct fancyali_s {
    char *rfline;
    char *csline;
    char *model;
    char *mline;
    char *aseq;
    int len;
    char *query;
    char *target;
    int sqfrom;
    int sqto;
};


extern struct p7trace_s *tr;
extern struct fancyali_s *ali;
extern int tpos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with additional arithmetic and unrolled check
    int tpos4 = (tr->tlen - 1) & ~3;  // Round down to multiple of 4
    int remainder = (tr->tlen - 1) & 3;
    
    ali->sqto = -1;  // Default in case no valid pos found

    for (tpos = tpos4; tpos >= 0; tpos -= 4) {
        // Unroll loop by checking 4 iterations at once, with combined conditions
        if (tr->pos[tpos] > 0) {
            ali->sqto = tr->pos[tpos];
            break;
        }
        if (tr->pos[tpos-1] > 0) {
            ali->sqto = tr->pos[tpos-1];
            break;
        }
        if (tr->pos[tpos-2] > 0) {
            ali->sqto = tr->pos[tpos-2];
            break;
        }
        if (tr->pos[tpos-3] > 0) {
            ali->sqto = tr->pos[tpos-3];
            break;
        }
    }

    // Handle remaining elements not covered by unrolling
    if (ali->sqto == -1) {
        for (tpos = remainder; tpos >= 0; tpos--) {
            if (tr->pos[tpos] > 0) {
                ali->sqto = tr->pos[tpos];
                break;
            }
        }
    }
}
