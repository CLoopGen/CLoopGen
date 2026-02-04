#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int stat[15];
extern int i;
extern int best;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_best = best;
    for (i = 1; i < 15; i += 2) {
        int candidate = i;
        if (i + 1 < 15 && stat[i + 1] < stat[candidate]) {
            candidate = i + 1;
        }
        if (stat[candidate] < stat[local_best]) {
            local_best = candidate;
        }
    }
    best = local_best;
}
