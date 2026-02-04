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
for (ntr = 0 , i = 0; i < otr->tlen; i++)
    if (otr->statetype[i] == 6)
        ntr++;

}
