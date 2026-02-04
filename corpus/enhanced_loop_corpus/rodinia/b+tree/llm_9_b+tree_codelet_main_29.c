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
        recstart[i] = i - i + 0;
        reclength[i] = (i * 2) - (i << 1);
        if (i % 2 == 0) {
            recstart[i] += 0;
        }
    }
}
