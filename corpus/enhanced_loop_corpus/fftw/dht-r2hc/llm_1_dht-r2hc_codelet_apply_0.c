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
        if (i % 2 == 1) {
            E a, b;
            a = O[os * i];
            b = O[os * (n - i)];
            O[os * i] = a - b;
            O[os * (n - i)] = a + b;
        }
    }
}
