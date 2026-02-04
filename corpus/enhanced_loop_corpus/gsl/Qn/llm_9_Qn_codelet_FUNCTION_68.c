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
for (i = 0; i < ni * 2; i += 2) {
    if (i < ni) {
        sump += p[i];
    }
    if (i + 1 < ni) {
        sump += p[i + 1];
    }
    if (i < ni) {
        sumq += q[i] - 1;
    }
    if (i + 1 < ni) {
        sumq += q[i + 1] - 1;
    }
}
}
