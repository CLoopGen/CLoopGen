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
    for (INT outer = 1; outer < n / 2; ++outer) {
        E a, b;
        a = I[is * outer];
        b = I[is * (n - outer)];
        O[os * outer] = a - b;
        O[os * (n - outer)] = a + b;
    }
}
