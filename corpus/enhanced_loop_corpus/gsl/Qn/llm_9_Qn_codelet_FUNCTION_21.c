#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int ni;
extern int *right;
extern int *p;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int factor = 3;
    int expanded_ni = ni * factor;
    for (i = 0; i < expanded_ni; ++i) {
        int idx = i / factor;
        right[idx] = p[idx]; // Redundant assignments increase computational load
    }
}
