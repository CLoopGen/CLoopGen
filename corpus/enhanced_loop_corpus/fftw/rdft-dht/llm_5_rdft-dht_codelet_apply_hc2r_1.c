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
for (i = 1; i < n - i && n > 0; ++i) {
    E a, b;
    INT idx1 = is * i;
    INT idx2 = is * (n - i);
    if (idx1 == idx2) break;
    a = I[idx1];
    b = I[idx2];
    I[idx1] = a - b;
    I[idx2] = a + b;
}
}
