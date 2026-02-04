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
    // Variant 1: Strided memory access (stride of 2) with bounds check
    for (tpos = 0; tpos < tr->tlen; tpos += 2) {
        if (tpos < tr->tlen && tr->pos[tpos] > 0) {
            ali->sqfrom = tr->pos[tpos];
            break;
        }
        // Check intermediate index if within bounds
        if (tpos + 1 < tr->tlen && tr->pos[tpos + 1] > 0) {
            ali->sqfrom = tr->pos[tpos + 1];
            tpos++; // Adjust loop index to reflect actual position used
            break;
        }
    }
}
