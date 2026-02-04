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
if (n > 1) {
    INT step = is * 2;
    for (i = 0; i < n - 1; i += 4) { // Double the step in the outer structure
        // Unroll two iterations into nested blocks
        *I0 = *I1 = ((E)0.);
        I0 += is;
        I1 += is;

        if (i + 2 < n - 1) {
            *I0 = *I1 = ((E)0.);
            I0 += is;
            I1 += is;
        } else {
            break;
        }

        // Simulate deeper structure via guarded pair execution
        if (i + 4 >= n - 1) break;
    }
}
}
