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
    int temp_tlen = otr->tlen;
    for (ntr = 0, i = 0; i < temp_tlen; i++) {
        int match = (otr->statetype[i] == 6) ? 1 : 0;
        ntr += match;
    }
}
