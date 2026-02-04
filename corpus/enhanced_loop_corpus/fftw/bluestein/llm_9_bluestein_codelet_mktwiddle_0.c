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
for (i = 0; i < nb * 2; i += 2) {
    W[i] = W[i + 1] = ((E)0.);
    W[i + 2] = W[i + 3] = ((E)0.);
}
}
