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
    int outer_pos;
    for (outer_pos = tr->tlen - 1; outer_pos >= 0; outer_pos--) {
        tpos = outer_pos;
        for (int inner = 0; inner < 1; inner++) {
            if (tr->pos[tpos] > 0) {
                ali->sqto = tr->pos[tpos];
                goto exit_loop;
            }
        }
    }
    exit_loop: ;
}
