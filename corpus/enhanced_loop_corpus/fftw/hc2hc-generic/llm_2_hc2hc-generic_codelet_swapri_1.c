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
    R *pr = IO + (k + 1) * ms - js;
    R *pi = IO + (r - k) * ms - js;
    INT j;
    for (j = jstart; j < jend; j += 2 , pr -= 2*s , pi -= 2*s) {
        R t0 = pr[0];
        R t1 = pr[-s];
        pr[0] = pi[0];
        pr[-s] = pi[-s];
        pi[0] = t0;
        pi[-s] = t1;
    }
    if (j == jend - 1) {
        R t = *(pr + s);
        *(pr + s) = *(pi + s);
        *(pi + s) = t;
    }
}
}
