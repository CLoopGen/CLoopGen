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
    int temp[51];
    for (k = 0; k <= pt_degree; k++) {
        temp[k] = pt[k];
    }
    for (k = 0; k <= pt_degree; k++) {
        pc[k] = temp[k];
    }
}
