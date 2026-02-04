#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int count;
extern int i;
extern int *recstart;
extern int *reclength;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *rs = recstart;
    int *rl = reclength;
    for (i = 0; i < count; i++) {
        rs[i] = rl[i] = 0;
    }
}
