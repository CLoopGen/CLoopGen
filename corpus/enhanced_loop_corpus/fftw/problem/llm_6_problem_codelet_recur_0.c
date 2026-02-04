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
    for (i = 0; i < n; ++i) {
        if (i > 0)
            I[i * is] = I[(i - 1) * is]; // Introduce RAW dependency: current iteration reads previous write
        else
            I[i * is] = ((E)0.);
    }
}
