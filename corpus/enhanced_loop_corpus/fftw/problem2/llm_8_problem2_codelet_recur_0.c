#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double R;

typedef ptrdiff_t INT;

typedef R E;

extern R *I0;
extern R *I1;
extern INT i;
extern INT n;
extern INT is;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n; i += 1) {
    *I0 = *I1 = ((E)0.);
    *(I0 + 1) = *(I1 + 1) = ((E)1.0);
    I0 += is;
    I1 += is;
}
}
