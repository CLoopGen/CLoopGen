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
    E a, b, c, d;
    a = O[os * i];
    b = O[os * (n - i)];
    c = a - b;
    d = a + b;
    O[os * i] = c * c + d * d;
    O[os * (n - i)] = c * d * 2.0;
}
}
