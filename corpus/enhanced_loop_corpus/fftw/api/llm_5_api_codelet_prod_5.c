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
    for (i = 0; i < rnk; ++i) {
        if (local_n[i] == 0) break;
        N *= local_n[i];
    }
}
