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



void loop() {
    int j;
    for (i = 0; i < tr->tlen; i += 2) {
        if (i + 1 < tr->tlen) {
            ndom += (tr->statetype[i] == 6) + (tr->statetype[i + 1] == 6);
        } else {
            ndom += (tr->statetype[i] == 6);
        }
    }
}
