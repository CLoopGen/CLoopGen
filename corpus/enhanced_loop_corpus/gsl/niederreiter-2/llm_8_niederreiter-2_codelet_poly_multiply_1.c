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
int i;
for (k = 0; k <= pt_degree; k++) {
    pc[k] = 0;
    for (i = 0; i < pt[k]; i++) {
        pc[k] += (i * 2 + 1);
    }
}
}
