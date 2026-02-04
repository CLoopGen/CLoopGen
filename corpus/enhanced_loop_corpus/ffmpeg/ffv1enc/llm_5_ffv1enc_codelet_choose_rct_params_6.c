#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int stat[15];
extern int i;
extern int best;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < 15; i++) {
        if (stat[i] >= stat[best]) continue;
        best = i;
    }
}
