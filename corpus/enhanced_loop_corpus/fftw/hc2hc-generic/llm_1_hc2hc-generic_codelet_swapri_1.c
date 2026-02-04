#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double R;

typedef ptrdiff_t INT;

extern R *IO;
extern INT r;
extern INT s;
extern INT jstart;
extern INT jend;
extern INT k;
extern INT ms;
extern INT js;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 0; k + k < r; ++k) {
    R *pr_base = IO + (k + 1) * ms - js;
    R *pi_base = IO + (r - k) * ms - js;
    INT j;
    for (INT offset = jstart; offset < jend; offset += 1) {
        R *pr = pr_base - (offset - jstart) * s;
        R *pi = pi_base - (offset - jstart) * s;
        R t = *pr;
        *pr = *pi;
        *pi = t;
    }
}
}
