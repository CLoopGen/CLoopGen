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
extern E ri;
extern E ir;
extern E ii;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Consecutive memory access with precomputed base pointers
INT offset = 0;
for (i = 1; i + i < n; ++i) {
    rr += x[offset + 0] * w[offset / 2];
    ir += x[offset + 1] * w[offset / 2];
    ri += x[offset + 2] * w[offset / 2 + 1];
    ii += x[offset + 3] * w[offset / 2 + 1];
    offset += 4;  // Advance x by 4 elements each iteration
}
}
