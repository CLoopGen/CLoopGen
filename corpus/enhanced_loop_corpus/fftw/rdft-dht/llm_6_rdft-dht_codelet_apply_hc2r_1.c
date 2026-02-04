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
    E a, b;
    a = I[is * i];
    b = I[is * (n - i)];
    E temp1 = a - b;
    E temp2 = a + b;
    I[is * (n - i)] = temp2;
    I[is * i] = temp1;
}
}
