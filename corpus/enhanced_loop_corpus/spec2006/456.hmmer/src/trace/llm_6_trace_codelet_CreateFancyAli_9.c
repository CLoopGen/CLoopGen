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
    int temp_sqto = 0;
    for (int i = tr->tlen - 1; i >= 0; i--) {
        if (tr->pos[i] > 0) {
            temp_sqto = tr->pos[i];
            break;
        }
    }
    ali->sqto = temp_sqto;
}
