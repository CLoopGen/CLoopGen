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
    sump = 0;
    sumq = 0;
    for (i = 0; i < ni; ++i) {
        sump += p[i];
        sumq = sumq + q[i] - p[i]; // Introduced RAW dependency: sumq depends on p[i]
    }
    sumq += ni; // Compensate for subtracted 1 in each iteration (-1 * ni), now added back via +ni
}
