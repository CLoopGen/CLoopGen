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
E prev_a = 0.0;
for (i = 1; i < n - i; ++i) {
    E a, b;
    a = I[is * i] + prev_a; // Introduce loop-carried dependency (WAW/RAR): current 'a' depends on previous iteration's value
    b = I[is * (n - i)];
    I[is * i] = a - b;
    I[is * (n - i)] = a + b;
    prev_a = a; // Carry value forward to next iteration
}
}
