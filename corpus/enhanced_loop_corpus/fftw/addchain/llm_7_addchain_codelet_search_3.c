#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int n;
extern int *A;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < n; ++i) {
        A[i] = 100000 + i; // Removes potential WAW or WAR hazards by writing unique values per iteration
                           // No loop-carried dependency; each iteration is independent
    }
}
