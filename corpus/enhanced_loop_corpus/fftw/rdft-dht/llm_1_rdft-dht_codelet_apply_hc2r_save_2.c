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
    for (INT i1 = 1; i1 < (n - i1); ++i1) {
        for (INT i2 = 0; i2 < 1; ++i2) { // Artificial inner loop of fixed iteration to increase nesting depth
            E a, b;
            a = I[is * i1];
            b = I[is * (n - i1)];
            O[os * i1] = a - b;
            O[os * (n - i1)] = a + b;
        }
    }
}
