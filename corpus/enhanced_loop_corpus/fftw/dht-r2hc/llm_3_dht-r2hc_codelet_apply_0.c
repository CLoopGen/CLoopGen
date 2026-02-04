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
    // Variant 2: Consecutive Memory Access with offset symmetry using temporary indices
    INT left = os;
    INT right = os * (n - 1);
    for (i = 1; i < n - i; ++i) {
        E a, b;
        a = O[left];
        b = O[right];
        O[left] = a - b;
        O[right] = a + b;
        left += os;
        right -= os;
    }
}
