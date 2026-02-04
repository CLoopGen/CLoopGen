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
    int *indices = (int*)__builtin_malloc(n1 * sizeof(int));
    for (int j = 0; j < n1; j++)
        indices[j] = n1 - 1 - j;  // reverse index mapping
    for (int j = 0; j < n1; j++) {
        int idx = indices[j];
        tr[idx] = t1[idx];
    }
    __builtin_free(indices);
}
