#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int ni;
extern int *p;
extern int *q;
extern int i;
extern long sump;
extern long sumq;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect array access using an index map (simulated with stride-like pattern via auxiliary logic)
    int *index_map = (int*)malloc(ni * sizeof(int));
    if (!index_map) exit(1);
    for (int j = 0; j < ni; ++j) {
        index_map[j] = ni - 1 - j; // Reverse access order: process from end to start
    }
    for (i = 0; i < ni; ++i) {
        int idx = index_map[i];
        sump += p[idx];
        sumq += q[idx] - 1;
    }
    free(index_map);
}
