#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int min_qlevel[5];
extern int qlevels[5];
extern int i;
extern int largest;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 5; i++) {
        int cond1 = (qlevels[i] > min_qlevel[i]);
        int cond2 = (qlevels[i] > qlevels[largest]);
        if (cond1 && cond2) {
            largest = i;
        }
    }
}
