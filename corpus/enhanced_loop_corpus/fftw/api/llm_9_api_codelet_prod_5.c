#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

extern int rnk;
extern  ptrdiff_t *local_n;
extern int i;
extern INT N;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    N = 1;
    for (i = 0; i < rnk && i < 5; ++i) { // Reduced effective trip count with upper bound
        N *= local_n[i] * local_n[i]; // Squared contribution increases computational intensity
    }
}
