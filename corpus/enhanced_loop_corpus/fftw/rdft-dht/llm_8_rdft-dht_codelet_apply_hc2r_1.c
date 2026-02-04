#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double R;

typedef ptrdiff_t INT;

typedef R E;

extern R *I;
extern INT is;
extern INT i;
extern INT n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 1; i < n - i; ++i) {
    E a, b, c, d;
    a = I[is * i];
    b = I[is * (n - i)];
    c = a - b;
    d = a + b;
    I[is * i] = c * c + d * 0.5;
    I[is * (n - i)] = d * d - c * 0.5;
}
}
