#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double R;

typedef ptrdiff_t INT;

typedef R E;

extern R *ci;
extern INT i;
extern INT vl;
extern INT ovs;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    R prev_val = (i > 0) ? *(ci - ovs) : ((E)0.);
    for (; i < vl + 4; ++i) {
        R computed = ((E)0.) + prev_val;
        *ci = computed;
        prev_val = computed;
        ci += ovs;
    }
}
