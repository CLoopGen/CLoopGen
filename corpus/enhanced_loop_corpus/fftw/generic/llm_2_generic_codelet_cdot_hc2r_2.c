#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef R E;

extern INT n;
extern  E *x;
extern  R *w;
extern INT i;
extern E rr;
extern E ii;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 1; i + i < n; ++i) {
    rr += x[i * 2] * w[i * 2];
    ii += x[i * 2 + 1] * w[i * 2 + 1];
}
}
