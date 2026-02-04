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
    if (pt_degree >= 0) {
        pc[0] = pt[0];
        for (k = 1; k <= pt_degree; k++) {
            pc[k] = pc[k-1] + (pt[k] - pt[k-1]);
        }
    }
}
