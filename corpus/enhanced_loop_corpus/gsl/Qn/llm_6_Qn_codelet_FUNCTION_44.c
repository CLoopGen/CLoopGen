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
    long temp_sump = 0;
    long temp_sumq = 0;
    for (i = 0; i < ni; ++i) {
        temp_sump += p[i];
        temp_sumq += q[i] - 1;
    }
    sump += temp_sump;
    sumq += temp_sumq;
}
