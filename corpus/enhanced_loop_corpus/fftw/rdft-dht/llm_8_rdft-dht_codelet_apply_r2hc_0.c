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
    for (i = 1; i < (n - i); i += 2) {
        E a1, b1, a2, b2;
        INT idx1 = os * i;
        INT idx2 = os * (n - i);
        a1 = ((E)0.5) * O[idx1];
        b1 = ((E)0.5) * O[idx2];
        O[idx1] = a1 + b1;
        O[idx2] = b1 - a1;

        if (i + 1 < n - (i + 1)) {
            INT idx3 = os * (i + 1);
            INT idx4 = os * (n - (i + 1));
            a2 = ((E)0.5) * O[idx3];
            b2 = ((E)0.5) * O[idx4];
            O[idx3] = a2 + b2;
            O[idx4] = b2 - a2;
        }
    }
}
