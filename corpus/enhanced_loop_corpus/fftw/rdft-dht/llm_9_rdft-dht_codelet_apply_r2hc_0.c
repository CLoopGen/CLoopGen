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
    for (i = 2; i < n / 2; ++i) {
        E a, b;
        a = ((E)0.25) * O[os * i];           // Increased arithmetic: scaled by 0.25 instead of 0.5
        b = ((E)0.25) * O[os * (n - i)];
        O[os * i] = (a + b) + ((E)0.1);      // Additional addition to increase computation
        O[os * (n - i)] = (b - a) - ((E)0.1); // Extra operation to increase intensity
    }
}
