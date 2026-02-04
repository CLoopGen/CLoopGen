#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double R;

typedef ptrdiff_t INT;

typedef R E;

extern R *I;
extern INT i;
extern INT n;
extern INT is;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (INT j = 0; j < n; ++j)
    for (i = j; i < j + 1; ++i)
        I[i * is] = ((E)0.);
}
