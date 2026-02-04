#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef R E;

extern INT i;
extern INT nb;
extern R *W;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access - traverse array with stride of 2, processing even and odd indices separately
    INT step = 2;
    INT limit = 2 * nb;
    for (i = 0; i < limit; i += step) {
        W[i]     = ((E)0.);
        W[i + 1] = ((E)0.);
    }
    // Note: Here, loop counter i is repurposed as a byte/element index rather than iteration count
    // This reflects a strided access pattern across the W array
}
