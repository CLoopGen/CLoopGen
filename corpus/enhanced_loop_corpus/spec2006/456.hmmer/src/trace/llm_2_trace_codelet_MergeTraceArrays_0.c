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
    int j;
    for (j = 0; j < n1; j += 2) {
        tr[j] = t1[j];
        if (j + 1 < n1)
            tr[j + 1] = t1[j + 1];
    }
}
