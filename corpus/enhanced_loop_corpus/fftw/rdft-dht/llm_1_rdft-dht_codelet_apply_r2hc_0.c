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
if (n > 2) {
    for (i = 1; i < n - i; ++i) {
        E a, b;
        a = ((E)0.5) * O[os * i];
        b = ((E)0.5) * O[os * (n - i)];
        O[os * i] = a + b;
        O[os * (n - i)] = b - a;

        for (INT j = 0; j < 1; ++j) {
            if (i + j == n - (i + j)) break;
        }
    }
}
}
