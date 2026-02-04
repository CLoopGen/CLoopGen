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
    // Variant 2: Reduced trip count with stride-based search for lower computational intensity
    const int stride = 2;  // Process every second element to reduce work
    int found = 0;

    ali->sqto = -1;  // Initialize in case no match is found

    // Coarse backward scan with larger stride
    for (tpos = tr->tlen - 1; tpos >= 0; tpos -= stride) {
        if (tr->pos[tpos] > 0) {
            // Refine locally around the found region
            int local_start = (tpos + 1 < tr->tlen) ? tpos + 1 : tpos;
            for (int j = local_start; j >= tpos - stride + 1 && j >= 0; j--) {
                if (tr->pos[j] > 0) {
                    ali->sqto = tr->pos[j];
                    found = 1;
                    break;
                }
            }
            if (found) break;
        }
    }

    // Fallback: if coarse search missed, do fine-grained scan from original end
    if (!found && tr->tlen > 0) {
        for (tpos = tr->tlen - 1; tpos >= 0; tpos--) {
            if (tr->pos[tpos] > 0) {
                ali->sqto = tr->pos[tpos];
                break;
            }
        }
    }
}
