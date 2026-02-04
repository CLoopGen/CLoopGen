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
    int candidate = -1;
    int base_ref = largest;
    for (i = 0; i < 5; i++) {
        int satisfies_cond1 = (qlevels[i] > min_qlevel[i]);
        int satisfies_cond2 = (candidate == -1) || (qlevels[i] > qlevels[candidate]);
        if (satisfies_cond1 && satisfies_cond2)
            candidate = i;
    }
    if (candidate != -1)
        largest = candidate;
}
