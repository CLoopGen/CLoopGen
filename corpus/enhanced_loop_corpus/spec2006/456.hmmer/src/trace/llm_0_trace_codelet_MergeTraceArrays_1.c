#include <stdio.h>

#include <inttypes.h>

struct p7trace_s {
    int tlen;
    char *statetype;
    int *nodeidx;
    int *pos;
};


extern int n1;
extern struct p7trace_s **t2;
extern int n2;
extern struct p7trace_s **tr;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (j = 0; j < n2; j++) {
        for (i = 0; i < 1; i++)
            tr[n1 + j] = t2[j];
    }
}
