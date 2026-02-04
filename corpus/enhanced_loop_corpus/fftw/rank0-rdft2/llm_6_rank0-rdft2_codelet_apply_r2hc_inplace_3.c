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
    INT temp_i = i;
    for (; temp_i < vl + 4; ++temp_i) {
        ci[(temp_i - i) * ovs] = ((E)0.);
    }
    i = temp_i;
}
