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
    ntr = 0;
    for (i = 0; i < otr->tlen; i += 2) {
        if (i + 1 < otr->tlen) {
            ntr += (otr->statetype[i] == 6) + (otr->statetype[i+1] == 6);
        } else {
            ntr += (otr->statetype[i] == 6);
        }
    }
}
