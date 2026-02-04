#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

extern INT n;
extern INT s;
extern int i;
extern INT *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
INT i1;
for (i1 = 0; i1 < n; ++i1)
    for (i = 0; i < 1; ++i)
        p[i1] = s * i1;
}
