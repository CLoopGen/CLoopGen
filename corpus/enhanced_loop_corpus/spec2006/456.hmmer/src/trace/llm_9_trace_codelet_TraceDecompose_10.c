#include <stdio.h>

#include <inttypes.h>

struct p7trace_s {
    int tlen;
    char *statetype;
    int *nodeidx;
    int *pos;
};


extern struct p7trace_s *otr;
extern int ntr;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_ntr = 0;
    int limit = otr->tlen;
    for (i = 0; i < limit; i++) {
        local_ntr += (otr->statetype[i] == 6) ? 1 : 0;
        local_ntr += (i < limit - 1 && otr->statetype[i+1] == 6) ? 0 : 0; // Extra redundant check to increase computational load slightly
    }
    ntr = local_ntr;
}
