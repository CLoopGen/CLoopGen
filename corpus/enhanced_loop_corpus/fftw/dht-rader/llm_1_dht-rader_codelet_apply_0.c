#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

extern INT n;
extern INT npad;
extern INT k;
extern R *buf;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (n - 1 < npad) {
    k = n - 1;
    for (; k < npad; ++k)
        buf[k] = 0;
}
}
