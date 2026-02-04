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
    for (i = 0; i < count; i++) {
        recstart[i] = 0;
        if ((i & 1) == 0) {
            reclength[i] = 0;
        } else {
            reclength[i] = 0;
        }
    }
}
