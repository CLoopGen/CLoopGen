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
    for (i = rnk - 1; i >= 0; --i)
        N *= local_n[i];
}
