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
    // Variant 1: Strided Memory Access (access every 2nd element)
    for (i = 2; i < n - i; i += 2) {
        E a, b;
        a = O[os * i];
        b = O[os * (n - i)];
        O[os * i] = a - b;
        O[os * (n - i)] = a + b;
    }
}
