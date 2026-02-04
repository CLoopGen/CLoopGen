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
    for (i = 0; i < count * 2; i += 2) {
        recstart[i / 2] = i - i;
        reclength[i / 2] = 0 * i;
    }
}
