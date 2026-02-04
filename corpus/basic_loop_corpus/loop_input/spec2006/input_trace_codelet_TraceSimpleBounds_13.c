#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct p7trace_s {
    int tlen;
    char *statetype;
    int *nodeidx;
    int *pos;
};

struct p7trace_s *tr;
int i2;
int k2;
int tpos;

void init_vars() {
    // Allocate a trace with approximately 10 million elements to achieve ~0.01 sec runtime
    const int size = 10000000;
    
    tr = (struct p7trace_s *)malloc(sizeof(struct p7trace_s));
    if (!tr) exit(1);
    
    tr->tlen = size;
    tr->statetype = (char *)malloc(size * sizeof(char));
    tr->nodeidx = (int *)malloc(size * sizeof(int));
    tr->pos = (int *)malloc(size * sizeof(int));
    
    if (!tr->statetype || !tr->nodeidx || !tr->pos) exit(1);
    
    // Initialize arrays with meaningful values
    for (int i = 0; i < size; i++) {
        // Fill with mostly 0s, some 1s and 2s near the end to trigger conditions
        tr->statetype[i] = 0;
        tr->nodeidx[i] = size - i;  // decreasing values
        tr->pos[i] = size - i;
    }
    
    // Place a statetype == 1 at position size/2 and at the very end
    tr->statetype[size/2] = 1;
    tr->statetype[size-1] = 2;
    
    // Ensure that when scanning backwards, we hit type 2 first, then type 1
    // This ensures k2 gets set from type 2, then i2 gets set and loop breaks on type 1
    
    i2 = -1;
    k2 = -1;
    tpos = 0;
}