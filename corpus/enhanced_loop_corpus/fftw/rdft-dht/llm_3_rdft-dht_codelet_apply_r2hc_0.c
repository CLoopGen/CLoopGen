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
INT stride = os * 2;
for (i = 1; i < n - i; ++i) {
    INT base_idx = os * n - os * i;
    E a, b;
    a = ((E)0.5) * O[base_idx - os];
    b = ((E)0.5) * O[base_idx];
    O[base_idx - os] = a + b;
    O[base_idx] = b - a;
}
}
