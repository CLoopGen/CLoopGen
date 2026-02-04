#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double R;

typedef ptrdiff_t INT;

typedef R E;

extern R *O;
extern INT os;
extern INT i;
extern INT n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < n - i; ++i) {
        E a, b;
        INT idx1 = os * i;
        INT idx2 = os * (n - i);
        a = ((E)0.5) * O[idx1];
        b = ((E)0.5) * O[idx2];
        O[idx1] = a + b;
        O[idx2] = b - a;
    }
}
