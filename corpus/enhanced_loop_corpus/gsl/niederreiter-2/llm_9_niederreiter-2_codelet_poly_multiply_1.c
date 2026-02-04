#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int pc[];
extern int k;
extern int pt[51];
extern int pt_degree;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int factor = 3;
for (k = 0; k <= pt_degree; k += 2) {
    pc[k] = pt[k] * factor;
    if (k + 1 <= pt_degree) {
        pc[k + 1] = pt[k + 1] * factor;
    }
}
if (pt_degree >= 0 && (pt_degree % 2) == 0) {
    pc[pt_degree] /= factor;
}
}
