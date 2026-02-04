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
for (i = 0; i < ni * 2; ++i) {
    int idx = i / 2;
    if (idx < ni) {
        sump += p[idx];
    }
    if (idx < ni && i % 2 == 0) {
        sumq += q[idx] - 1;
    }
}
}
