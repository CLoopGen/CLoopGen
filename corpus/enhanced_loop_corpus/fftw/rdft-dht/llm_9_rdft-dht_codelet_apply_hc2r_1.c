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
for (i = 2; i < n - i; i += 2) {
    E a1, b1, a2, b2;
    a1 = I[is * i];
    b1 = I[is * (n - i)];
    a2 = I[is * (i + 1)];
    b2 = I[is * (n - i - 1)];
    I[is * i] = a1 - b1;
    I[is * (n - i)] = a1 + b1;
    I[is * (i + 1)] = a2 - b2;
    I[is * (n - i - 1)] = a2 + b2;
}
}
