#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double R;

typedef ptrdiff_t INT;

typedef R E;

extern R *I;
extern R *O;
extern INT is;
extern INT os;
extern INT i;
extern INT n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < n - i; ++i) {
        E a1, b1, a2, b2;
        INT idx1 = is * i;
        INT idx2 = is * (n - i);
        // Reorder memory accesses to eliminate potential WAW and WAR hazards
        // and remove loop-carried dependencies by computing all values before stores
        a1 = I[idx1];
        b1 = I[idx2];
        a2 = a1 - b1;
        b2 = a1 + b1;
        // Store results in reverse order to vary write pattern without changing semantics
        O[os * (n - i)] = b2;
        O[os * i] = a2;
    }
}
