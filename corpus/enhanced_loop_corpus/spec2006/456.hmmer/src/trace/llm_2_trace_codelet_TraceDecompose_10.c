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
    int *nodeidx = otr->nodeidx;
    char *statetype = otr->statetype;
    int tlen = otr->tlen;
    for (ntr = 0, i = 0; i < tlen; i += 2) {
        if (i + 1 < tlen) {
            if (statetype[i] == 6) ntr++;
            if (statetype[i+1] == 6) ntr++;
        } else {
            if (statetype[i] == 6) ntr++;
        }
    }
}
