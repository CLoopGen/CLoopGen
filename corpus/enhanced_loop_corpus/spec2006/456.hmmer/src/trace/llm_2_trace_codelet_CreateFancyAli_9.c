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
    // Variant 1: Consecutive memory access with reverse traversal using pointer arithmetic
    int *pos_ptr = tr->pos + tr->tlen - 1;
    for (tpos = tr->tlen - 1; tpos >= 0; tpos--, pos_ptr--)
        if (*pos_ptr > 0) {
            ali->sqto = *pos_ptr;
            break;
        }
}
