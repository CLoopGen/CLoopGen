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
    // Variant 2: Indirect array access using an index mapping (simulated via pointer arithmetic)
    int *index_map = tr->nodeidx ? tr->nodeidx : &(tr->pos[0]); // Use nodeidx as indirect indices if available, else fall back
    int limit = tr->nodeidx ? tr->tlen : tr->tlen;
    
    for (tpos = 0; tpos < limit; tpos++) {
        int mapped_index = index_map[tpos]; // Indirect access through index map
        if (mapped_index >= 0 && mapped_index < tr->tlen && tr->pos[mapped_index] > 0) {
            ali->sqfrom = tr->pos[mapped_index];
            break;
        }
    }
}
