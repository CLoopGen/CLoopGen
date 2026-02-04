#include <stdio.h>

#include <inttypes.h>

struct p7trace_s {
    int tlen;
    char *statetype;
    int *nodeidx;
    int *pos;
};


extern struct p7trace_s **t1;
extern int n1;
extern struct p7trace_s **tr;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int k = 0;
    if (n1 > 0) {
        tr[0] = t1[0];
        for (k = 1; k < n1; k++) {
            tr[k] = t1[k];
            tr[k-1]->tlen = tr[k]->tlen; // Introduce WAW and RAW dependency: write after read/write on tlen
        }
    }
}
