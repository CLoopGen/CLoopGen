#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double R;

typedef ptrdiff_t INT;

extern R *O0;
extern R *O1;
extern INT n0;
extern INT os0;
extern INT i0;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    R prev = 0;
    for (i0 = 0; i0 < n0; ++i0) {
        INT idx = i0 * os0;
        O0[idx] = prev;
        prev = O1[idx] = i0 * 2.0;
    }
}
