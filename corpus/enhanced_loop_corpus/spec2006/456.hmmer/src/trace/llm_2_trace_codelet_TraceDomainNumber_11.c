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
    int *nodeidx_ptr = tr->nodeidx;
    char *statetype_ptr = tr->statetype;
    for (i = 0; i < tr->tlen; i++) {
        if (*(statetype_ptr + i) == 6)
            ndom++;
    }
}
