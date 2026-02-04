#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double R;

typedef ptrdiff_t INT;

typedef R E;

extern R *I;
extern R *O;
extern INT is;
extern INT os;
extern INT i;
extern INT n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (n > 2) {
    for (i = 1; i < n / 2; ++i) {
        E a, b, temp1, temp2;
        a = I[is * i];
        b = I[is * (n - i)];
        temp1 = a - b;
        temp2 = a + b;
        O[os * i] = temp1 * temp1;          // Square the difference
        O[os * (n - i)] = temp2 * temp2;    // Square the sum
    }
}
}
