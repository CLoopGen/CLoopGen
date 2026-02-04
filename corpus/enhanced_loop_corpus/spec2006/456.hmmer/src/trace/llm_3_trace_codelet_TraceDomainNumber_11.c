#include <stdio.h>

#include <inttypes.h>

struct p7trace_s {
    int tlen;
    char *statetype;
    int *nodeidx;
    int *pos;
};


extern struct p7trace_s *tr;
extern int i;
extern int ndom;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = 2;
    int limit = (tr->tlen + stride - 1) / stride;
    for (i = 0; i < limit; i++) {
        int idx = i * stride;
        if (idx < tr->tlen && tr->statetype[idx] == 6)
            ndom++;
    }
}
