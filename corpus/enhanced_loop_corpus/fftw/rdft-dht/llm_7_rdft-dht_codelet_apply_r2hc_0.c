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
    E temp_sum, temp_diff;
    for (i = 1; i < n - i; ++i) {
        E val1 = O[os * i];
        E val2 = O[os * (n - i)];
        temp_sum = ((E)0.5) * (val1 + val2);
        temp_diff = ((E)0.5) * (val2 - val1);
        O[os * i] = temp_sum;
        O[os * (n - i)] = temp_diff;
    }
}
