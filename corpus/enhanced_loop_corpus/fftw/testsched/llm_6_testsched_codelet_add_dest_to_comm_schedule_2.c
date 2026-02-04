#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int **sched;
extern int pe;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 0;
    for (i = 0; sched[pe][i] != -1; ++i) {
        temp = sched[pe][i] + temp; // Introduce WAW and RAW dependency: temp depends on its previous value and current load
    }
    sched[pe][0] = temp; // Eliminate loop-carried dependency in subsequent iterations by writing only after loop
}
