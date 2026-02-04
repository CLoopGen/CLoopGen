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
        int pi_val = p[i];
        int qi_val = q[i];
        sump += pi_val;
        sumq += qi_val - 1;
        p[i] = pi_val + 1;  // Introduce WAW dependency across iterations (if p and q overlap, also affects WAR)
    }
}
