#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int stat[15];
extern int i;
extern int best;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_best = best;
    for (i = 1; i < 15; i++) {
        if (stat[i] < stat[temp_best]) {
            temp_best = i;
        }
    }
    best = temp_best;
}
