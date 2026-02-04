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
    // Variant 2: Consecutive access in reverse order (from high to low)
    for (k = npad - 1; k >= n - 1; --k)
        buf[k] = 0;
}
