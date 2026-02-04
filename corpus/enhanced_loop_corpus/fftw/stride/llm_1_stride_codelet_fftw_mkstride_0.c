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
INT outer;
for (outer = 0; outer < n; ++outer) {
    i = outer;
    p[outer] = s * i;
}
}
